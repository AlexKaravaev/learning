#include "date.h"


Date::Date()
{
    year  = 0;
    month = 0;
    day   = 0;
}

/**
 * @brief Construct a new Date object.
 *
 * @param ts in format YYYY-MM-DD
*/
Date::Date(const std::string& ts)
{

    std::istringstream stream(ts);
    bool flag = true;

    flag = flag && (stream >> year);
    flag = flag && (stream.peek() == '-');
    stream.ignore(1);

    flag = flag && (stream >> month);
    flag = flag && (stream.peek() == '-');
    stream.ignore(1);

    flag = flag && (stream >> day);
    flag = flag && (stream.eof() );
    if (!flag)
    {
        throw std::invalid_argument("Wrong date format: " + ts);
    }

    // Check the values are meaningfull
    if(month<1 || month >12)
    {
        throw std::invalid_argument("Month value is invalid: " + std::to_string(month));
    }
    if(day<1 || day>31)
    {
        throw std::invalid_argument("Day value is invalid: " + std::to_string(day));
    }
}

int Date::GetYear() const
{
    return year;
}


int Date::GetMonth() const
{
    return month;
}

int Date::GetDay() const
{
    return day;
}

bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() == rhs.GetYear())
    {
        if(lhs.GetMonth() == rhs.GetMonth())
        {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

bool operator==(const Date& lhs, const Date& rhs)
{
    return (lhs.GetYear()==rhs.GetYear() && lhs.GetMonth()==rhs.GetMonth() && lhs.GetDay()==rhs.GetDay());
}

std::ostream& operator<<(std::ostream& stream, const Date& date)
{
    stream << std::setfill('0') << std::setw(4) << date.GetYear() << "-";
    stream << std::setfill('0') << std::setw(2) << date.GetMonth() << "-";
    stream << std::setfill('0') << std::setw(2) << date.GetDay();
    return stream;
}
