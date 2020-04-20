#pragma once
#include "date.h"

enum LogicalOperation
{
    Or,
    And
};

enum Comparison
{
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

class Node
{

public:
    Node(const Comparison& cmp);
    virtual bool Evaluate(const Date& date, const std::string& event) = 0;
protected:
    Comparison cmp;
};

class EmptyNode: Node
{

public:
    Node();
    bool Evaluate(const Date& date, const std::string& event) override;

};

class DateComparisonNode: Node
{

public:
    DateComparisonNode(const Comparison& cmp, const Date& date);
    bool Evaluate(const Date& date, const std::string& event) override;

private:
    const Date& date_;
};

class EventComparisonNode: Node
{

public:
    EventComparisonNode(const Comparison& cmp, const std::string& event);
    bool Evaluate(const Date& date, const std::string& event) override;


private:
    const std::string& event_;
};

class LogicalOperationNode: public Node
{
public:
    LogicalOperationNode(const Comparison& cmp, const Node& left, const Node& right);
    bool Evaluate(const Date& date, const std::string& event) override;

private:
    const EmptyNode left_, right_;
};