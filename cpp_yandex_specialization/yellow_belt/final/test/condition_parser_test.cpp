#include "condition_parser.h"

#include <iostream>
#include "gtest/gtest.h"
#include <sstream>

TEST(parse_condition_test, test_1)
{
  std::istringstream is("date != 2017-11-18");
  std::shared_ptr<Node> root = ParseCondition(is);
  EXPECT_EQ(root->Evaluate({2017, 1, 1}, ""), "Parse condition 1");
  EXPECT_EQ(!root->Evaluate({2017, 11, 18}, ""), "Parse condition 2");
}

TEST(parse_condition_test, test_2)
{
  std::istringstream is(R"(event == "sport event")");
  std::shared_ptr<Node> root = ParseCondition(is);
  EXPECT_EQ(root->Evaluate({2017, 1, 1}, "sport event"), "Parse condition 3");
  EXPECT_EQ(!root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 4");
}

TEST(parse_condition_test, test_3)
{
  std::istringstream is("date >= 2017-01-01 AND date < 2017-07-01");
  std::shared_ptr<Node> root = ParseCondition(is);
  EXPECT_EQ(root->Evaluate({2017, 1, 1}, ""), "Parse condition 5");
  EXPECT_EQ(root->Evaluate({2017, 3, 1}, ""), "Parse condition 6");
  EXPECT_EQ(root->Evaluate({2017, 6, 30}, ""), "Parse condition 7");
  EXPECT_EQ(!root->Evaluate({2017, 7, 1}, ""), "Parse condition 8");
  EXPECT_EQ(!root->Evaluate({2016, 12, 31}, ""), "Parse condition 9");
}

TEST(parse_condition_test, test_4)
{
  std::istringstream is(R"(event != "sport event" AND event != "Wednesday")");
  std::shared_ptr<Node> root = ParseCondition(is);
  EXPECT_EQ(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 10");
  EXPECT_EQ(!root->Evaluate({2017, 1, 1}, "sport event"), "Parse condition 11");
  EXPECT_EQ(!root->Evaluate({2017, 1, 1}, "Wednesday"), "Parse condition 12");
}

TEST(parse_condition_test, test_5)
{
  std::istringstream is(R"(event == "holiday AND date == 2017-11-18")");
  std::shared_ptr<Node> root = ParseCondition(is);
  EXPECT_EQ(!root->Evaluate({2017, 11, 18}, "holiday"), "Parse condition 13");
  EXPECT_EQ(!root->Evaluate({2017, 11, 18}, "work day"), "Parse condition 14");
  EXPECT_EQ(root->Evaluate({1, 1, 1}, "holiday AND date == 2017-11-18"), "Parse condition 15");
}

TEST(parse_condition_test, test_5)
{
  std::istringstream is(R"(((event == "holiday" AND date == 2017-01-01)))");
  std::shared_ptr<Node> root = ParseCondition(is);
  EXPECT_EQ(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 16");
  EXPECT_EQ(!root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 17");
}

TEST(parse_condition_test, test_5)
{
  std::istringstream is(R"(date > 2017-01-01 AND (event == "holiday" OR date < 2017-07-01))");
  std::shared_ptr<Node> root = ParseCondition(is);
  EXPECT_EQ(!root->Evaluate({2016, 1, 1}, "holiday"), "Parse condition 18");
  EXPECT_EQ(root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 19");
  EXPECT_EQ(root->Evaluate({2017, 1, 2}, "workday"), "Parse condition 20");
  EXPECT_EQ(!root->Evaluate({2018, 1, 2}, "workday"), "Parse condition 21");
}

TEST(parse_condition_test, test_5)
{
  std::istringstream is(R"(date > 2017-01-01 AND event == "holiday" OR date < 2017-07-01)");
  std::shared_ptr<Node> root = ParseCondition(is);
  EXPECT_EQ(root->Evaluate({2016, 1, 1}, "event"), "Parse condition 22");
  EXPECT_EQ(root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 23");
  EXPECT_EQ(root->Evaluate({2017, 1, 2}, "workday"), "Parse condition 24");
  EXPECT_EQ(!root->Evaluate({2018, 1, 2}, "workday"), "Parse condition 25");
}

TEST(parse_condition_test, test_5)
{
  std::istringstream is(R"(((date == 2017-01-01 AND event == "holiday")))");
  std::shared_ptr<Node> root = ParseCondition(is);
  EXPECT_EQ(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 26");
  EXPECT_EQ(!root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 27");
}

TEST(parse_condition_test, test_5)
{
  std::istringstream is(R"(((event == "2017-01-01" OR date > 2016-01-01)))");
  std::shared_ptr<Node> root = ParseCondition(is);
  EXPECT_EQ(root->Evaluate({1, 1, 1}, "2017-01-01"), "Parse condition 28");
  EXPECT_EQ(!root->Evaluate({2016, 1, 1}, "event"), "Parse condition 29");
  EXPECT_EQ(root->Evaluate({2016, 1, 2}, "event"), "Parse condition 30");
}

