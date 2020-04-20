#include "node.h"


Node::Node(const Comparison& cmp):
    cmp(cmp)
{};

bool EmptyNode::Evaluate(const Date& date, const std::string& event)
{
    throw std::logic_error("Trying to evaluate empty node");
}


DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date):
    Node(cmp), date_(date)
{};

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event)
{
    if (cmp == Comparison::Equal)
        return date == this->date_;
    else if(cmp == Comparison::NotEqual)
        return !(date == this->date_);
    else if(cmp == Comparison::Less)
        return date < this->date_;
    else if(cmp == Comparison::LessOrEqual)
        return (date < this->date_) || (date == this->date_);
    else if(cmp == Comparison::Greater)
        return !(date < this->date_) && !(date == this->date_);
    else if(cmp == Comparison::GreaterOrEqual)
        return !(date < this->date_);
    else
        throw std::invalid_argument("No such comparison");
    
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const std::string& event): 
    Node(cmp), event_(event) 
{};

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event)
{
    if (cmp == Comparison::Equal)
        return event == this->event_;
    else if(cmp == Comparison::NotEqual)
        return event != this->event_;
    else
        throw std::logic_error("Operation on event, that is not EQUAL nor NOT_EQUAL");
}


LogicalOperationNode::LogicalOperationNode(const Comparison& cmp, const Node& left, const Node& right):
    Node(cmp), left_(left), right_(right)
{
}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event)
{

}