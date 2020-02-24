#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    if (names.count(year) == 0)
      names[year].second = "";
    names[year].first = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    if (names.count(year) == 0)
      names[year].first == "";
    names[year].second = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year

    string first_name("unknown"), last_name("unknown");
    for (const auto& v: names)
    {
       if (year<v.first)
        { 
          return "Incognito";
        }
        break;
    }
    for (const auto& [w_year, name]: names)
    {

      if (w_year <= year && name.second != "")
        last_name = name.second;
      if (w_year <= year && name.first != "")
        first_name = name.first;
    }

    if (first_name == "unknown")
        return last_name + string(" with unknown first name");
    if (last_name == "unknown")
        return first_name + string(" with unknown last name");;
    
    return first_name + string(" ") + last_name;
    
    
  }
private:
  map<int, pair<string, string> > names;
 
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
