// void TestParseEvent() {
//   {
//     istringstream is("event");
//     AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
//   }
//   {
//     istringstream is("   sport event ");
//     AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
//   }
//   {
//     istringstream is("  first event  \n  second event");
//     vector<string> events;
//     events.push_back(ParseEvent(is));
//     events.push_back(ParseEvent(is));
//     AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
//   }
// }

// void TestAll() {
//   TestRunner tr;
//   tr.RunTest(TestParseEvent, "TestParseEvent");
//   tr.RunTest(TestParseCondition, "TestParseCondition");
// }
