#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;


void PrintBuses(const map<string, vector<string> >& buses_stops)
{
  if (buses_stops.size() == 0 )
  {
    cout << "No buses" << endl;
    return;
  }
  for (auto& [bus, stops]: buses_stops)
  {
    cout << "Bus " << bus << ": ";
    for (auto& stop: stops)
    {
      cout << stop << " ";
    }
    cout << endl;
  }
}

void findBuses(const string& stop, map<string, vector<string> >& stops_buses)
{
  if (stops_buses.find(stop) == stops_buses.end())
  {
    cout << "No stop" << endl;
    return;
  }
  for (auto& bus: stops_buses[stop])
  {
    cout << bus << " ";
  }
  cout << endl;
}

void  FindStopsForBuses(const string& new_bus, map<string, vector<string> >& stops_buses, map<string, vector<string> >& buses_stops)
{
  if (buses_stops.find(new_bus) == buses_stops.end())
  {
    cout << "No bus" << endl;
    return;
  }
  for (const auto& stop: buses_stops[new_bus])
  {
    auto buses = stops_buses[stop];
    if (find(buses.begin(), buses.end(), new_bus) != buses.end())
    {
      cout << "Stop " << stop << ": ";
      if (buses.size() == 1)
      {
        cout << "no interchange " << endl;
        continue;
      }
      for (auto& bus: buses)
      {
        if (bus==new_bus)
          continue;
        cout << bus << " ";
      }
    }
    cout << endl;

  }
}

int main() {
  int n, n_stops;
  cin >> n;
  map<string, vector<string> > buses_stops;

  map<string, vector<string> > stops_buses;
  string cur_command, new_bus, cur_stop;
  for (auto i=0; i<n; i++)
  {
    cin >> cur_command;
    if (cur_command == "ALL_BUSES")
    {
      PrintBuses(buses_stops);
    }
    if (cur_command == "NEW_BUS")
    {
      cin >> new_bus;
      cin >> n_stops;
      while(n_stops>0)
      {
        cin >> cur_stop;
        buses_stops[new_bus].push_back(cur_stop);
        stops_buses[cur_stop].push_back(new_bus);
        n_stops--;
      }

    }
    if (cur_command=="BUSES_FOR_STOP")
    {
      cin >> cur_stop;
      findBuses(cur_stop, stops_buses);
      
    }
    if(cur_command == "STOPS_FOR_BUS")
    {
      cin >> new_bus;
      FindStopsForBuses(new_bus, stops_buses, buses_stops);
    }
  }
  return 0;
}
