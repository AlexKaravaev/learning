#include "database.h"

void Database::AddEvent(const Date& date, const std::string& event)
{
    event_list[date].insert(event);
}

bool Database::DeleteEvent(const Date& date, const std::string& event)
{
    auto res = event_list[date].erase(event);
    return res != 0;
}

int Database::DeleteDate(const Date& date){
    auto date_size = event_list[date].size();
    event_list.erase(date);
    return date_size;
}

std::vector<std::string> Database::Find(const Date& date) const{
    if (event_list.count(date))
        return std::vector<std::string>(event_list.at(date).begin(), event_list.at(date).end());
    else
        return std::vector<std::string>{};

}

void Database::Print(std::ostream& stream) const{
    for(auto& [date, events]: event_list){
        for(auto& event: events){
            stream << date << " " << event << std::endl;
        }
    }
}
