#include <iostream>
#include <iomanip>
#include <vector>
#include <exception>
#include <map>
#include <set>

using namespace std;

class Date
{
public:
    Date()
    {
        year = 0;
        month = 0;
        day = 0;
    }
    /**
     * @brief Construct a new Date object.
     *
     * @param ts in format YYYY-MM-DD
     */
    explicit Date(const string& ts)
    {

        istringstream stream(ts);

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
           throw invalid_argument("Wrong date format: " + ts);
        }

        // Check the values are meaningfull
        if(month<1 || month >12)
        {
            throw invalid_argument("Month value is invalid: " + to_string(month));
        }
        if(day<1 || day>31)
        {
            throw invalid_argument("Day value is invalid: " + to_string(day));
        }

    }

    [[nodiscard]] int GetYear() const
    {
        return year;
    }


    [[nodiscard]] int GetMonth() const
    {
        return month;
    }

    [[nodiscard]] int GetDay() const
    {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

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

ostream& operator<<(ostream& stream, const Date& date)
{
    stream << setfill('0') << setw(4) << date.GetYear() << "-";
    stream << setfill('0') << setw(2) << date.GetMonth() << "-";
    stream << setfill('0') << setw(2) << date.GetDay();
    return stream;
}

class Database {
public:

    void AddEvent(const Date& date, const string& event)
    {
        event_list[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event)
    {
        auto res = event_list[date].erase(event);
        return res != 0;
    }

    int  DeleteDate(const Date& date){
        auto date_size = event_list[date].size();
        event_list.erase(date);
        return date_size;
    }

    [[nodiscard]] vector<string> Find(const Date& date) const{
        if (event_list.count(date))
            return vector<string>(event_list.at(date).begin(), event_list.at(date).end());
        else
            return vector<string>{};

    }

    void Print() const{
        for(auto& [date, events]: event_list){
            for(auto& event: events){
                std::cout << date << " " << event << std::endl;
            }
        }
    }

private:
    map<Date, set<string>> event_list;
};


int main()
{
    Database db;
    string line;
    string command, date, event;
    Date d;
    try {
        while (getline(cin, line))
        {
            istringstream iss(line);
            if (!(iss >> command))
                continue;
            if(command=="Add" || command=="Del" || command=="Find"){
                iss >> date;

                d = Date(date);
                if(iss >> event)
                {
                    if(command == "Add")
                        db.AddEvent(d, event);
                    if(command == "Del") {
                        auto res=db.DeleteEvent(d, event);
                        if(res)
                            cout << "Deleted successfully" << endl;
                        else
                            cout << "Event not found" << endl;
                    }
                } else{
                    if(command=="Find") {
                        auto res=db.Find(d);
                        for(auto& found_event: res)
                            cout << found_event << endl;
                    }
                    else{
                        auto res=db.DeleteDate(d);
                        cout << "Deleted " << res << " events" << endl;
                    }
                }
            }
            else if(command=="Print")
                db.Print();
            else
                cout << "Unknown command: " << command;
        }
    }catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}