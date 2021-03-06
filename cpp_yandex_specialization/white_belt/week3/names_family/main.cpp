#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Person {
public:
  
  Person(const string& n_given_name, const string& n_given_last_name, int n_birth_year):birth_year(n_birth_year)
  {
    names[birth_year] = pair<string, string>(n_given_name, n_given_last_name);
  }

  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    if (year < birth_year)
      return;
    if (names.count(year) == 0)
      names[year].second = "";
    names[year].first = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    if (year < birth_year)
      return;
    if (names.count(year) == 0)
      names[year].first == "";
    names[year].second = last_name;

  }
  string GetFullName(int year)  const {
    // получить имя и фамилию по состоянию на конец года year
    if (year<birth_year)
      return "No person";
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


  string GetFullNameWithHistory(int year) const {
    if (year < birth_year)
      return "No person";
    string first_name("unknown"), last_name("unknown");
    vector<string> first_names, last_names;
    if (names.size() == 0)
      return "Incognito";
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
      {
        
        if (name.second != last_name && last_name!="unknown")
          last_names.push_back(last_name);
        last_name = name.second;
      }
      if (w_year <= year && name.first != "")
      {
        if (name.first != first_name && first_name!="unknown")
          first_names.push_back(first_name);
        first_name = name.first;
      }
    }
    string last_names_str(""), first_names_str("");
    if(last_names.size()>0)
    { 
      last_names_str += " (" + last_names[last_names.size() - 1];
      if (last_names.size()>1)
        for (auto i = last_names.size()-1; i>0; --i)
          last_names_str +=", " + last_names[i-1];
      last_names_str += ")";
    }
    if(first_names.size()>0)
    {
      first_names_str += " (" + first_names[first_names.size()-1];
      if (first_names.size()>1)
        for (auto i = first_names.size()-1; i>0; --i)
          first_names_str += ", " + first_names[i-1];
      first_names_str += ")";
    }
    
    if (first_name == "unknown")
        return last_name + last_names_str + string(" with unknown first name");
    if (last_name == "unknown")
        return first_name + first_names_str + string(" with unknown last name");;
    if(first_names_str==" (" || first_names_str==" ()")
      first_names_str = "";
    if(last_names_str==" ("  || last_names_str==" ()")
      last_names_str = "";
    return first_name + first_names_str +  string(" ") + last_name + last_names_str;
    
  }

private:
  map<int, pair<string, string> > names;
  int birth_year;
};


int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
