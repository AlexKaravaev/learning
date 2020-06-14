#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <set>
#include "date.h"



class Database
{
public:
    void AddEvent(const Date& date, const std::string& event);
    bool DeleteEvent(const Date& date, const std::string& event);
    int  DeleteDate(const Date& date);
    std::vector<std::string> Find(const Date& date) const;
    void Print(std::ostream& stream) const;
    template<class Predicate> int RemoveIf(Predicate p);
    template<class Predicate> std::vector<std::string> FindIf(Predicate p) const;
    std::string Last(const Date& date) const;
private:
    std::map<Date, std::set<std::string>> event_list;
};

template<class Predicate>
int Database::RemoveIf(Predicate p)
{
    return 5;
}

template<class Predicate>
std::vector<std::string> Database::FindIf(Predicate p) const
{

    return std::vector<std::string>({"test"});
}