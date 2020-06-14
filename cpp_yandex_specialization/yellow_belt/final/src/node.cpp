#include "node.h"



bool EmptyNode::Evaluate(const Date& date, const std::string& event) const
{
    throw std::logic_error("Trying to evaluate empty node");
}


DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date):
    cmp_(cmp), date_(date)
{};

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) const
{
    if (cmp_ == Comparison::Equal)
        return date == this->date_;
    else if(cmp_ == Comparison::NotEqual)
        return !(date == this->date_);
    else if(cmp_ == Comparison::Less)
        return date < this->date_;
    else if(cmp_ == Comparison::LessOrEqual)
        return (date < this->date_) || (date == this->date_);
    else if(cmp_ == Comparison::Greater)
        return !(date < this->date_) && !(date == this->date_);
    else if(cmp_ == Comparison::GreaterOrEqual)
        return !(date < this->date_);
    else
        throw std::invalid_argument("No such comparison");
    
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const std::string& event): 
    cmp_(cmp), event_(event)
{};

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const
{
    if (cmp_ == Comparison::Equal)
        return event == this->event_;
    else if(cmp_ == Comparison::NotEqual)
        return event != this->event_;
    else
        throw std::logic_error("Operation on event, that is not EQUAL nor NOT_EQUAL");
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, const std::shared_ptr<Node>& left,
                     const std::shared_ptr<Node>& right):
                     op_(op), left_(left), right_(right)
{
}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const
{
    return true;
}