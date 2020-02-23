#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


int main() {

  vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int n;
  cin >> n;
  string cur_command;
  int month_cursor(0);
  int date;
  string reminder;
  int j=0;
  vector< vector<string> > cur_month(days_in_months[month_cursor]);
  for(int i=0;i<n;i++)
  {
    cin >> cur_command;
    if (cur_command=="NEXT")
    {
      month_cursor++;
      if(month_cursor>11)
        month_cursor=0;
      //Initialize new month with previous reminders
      if(cur_month.size()>days_in_months[month_cursor])
      { 
        j = 0;
        for (auto elem: cur_month)
        {
          cout << j << ' ';
          for (auto rem: elem)
            cout << rem << ' ';
          cout << endl;
          j++;
        }
        for(auto k=days_in_months[month_cursor];k<cur_month.size();k++)
        {
          for (auto& rem: cur_month[k])
          {
            if (rem != "")
            {
              cur_month[days_in_months[month_cursor]-1].push_back(rem);
            }
          } 
        }
      }
      cur_month.resize(days_in_months[month_cursor]);
      j = 0;
      for (auto elem: cur_month)
      {
          cout << j << ' ';
          for (auto rem: elem)
            cout << rem << ' ';
          cout << endl;
          j++;
      }
    }
    if (cur_command=="ADD")
    {
      cin >> date;
      cin >> reminder;
      cur_month[date-1].push_back(reminder);
    }
    if (cur_command=="DUMP")
    {
      cin >> date;
      date-=1;
      cout << cur_month[date].size() << ' ';  
      for (auto i=0; i < cur_month[date].size(); i++)
      {
        cout << cur_month[date][i] << ' ';
      }
      cout << endl;
    }
  }

  return 0;
}
