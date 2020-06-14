#pragma once
#include <string>
#include <iomanip>
#include <exception>

class Date
{
public:
    Date();
    explicit Date(const std::string& ts);
    int GetYear()  const;
    int GetMonth() const;
    int GetDay()   const;
private:
    int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& stream, const Date& date);

Date ParseDate(std::istream& stream);

