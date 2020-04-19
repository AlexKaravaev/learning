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
    void Print() const;
private:
    std::map<Date, std::set<std::string>> event_list;
};