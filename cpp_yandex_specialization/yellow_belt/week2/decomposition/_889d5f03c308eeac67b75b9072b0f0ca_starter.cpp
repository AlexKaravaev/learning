#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
  string query_string;
  is >> query_string;
  if (query_string == "NEW_BUS")
  {
    q.stops.clear();
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stop_count;
    is >> stop_count;
    
    for (auto i=0;i<stop_count;i++)
    {
      is >> q.stop;
      q.stops.push_back(q.stop);
    }
  }
  else if (query_string == "BUSES_FOR_STOP")
  {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  }
  else if (query_string == "STOPS_FOR_BUS")
  {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  }
  else if (query_string == "ALL_BUSES")
    q.type = QueryType::AllBuses;
  return is;
}

struct BusesForStopResponse {
  // Наполните полями эту структуру
  vector<string> msg;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
  for (auto& msg_part: r.msg)
    os << msg_part;
  return os;
}

struct StopsForBusResponse {
  // Наполните полями эту структуру
  vector<string> msg;
  
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  for (auto& msg_part: r.msg)
    os << msg_part;
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
  vector<string> msg;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  for (auto& msg_part: r.msg)
    os << msg_part;
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
    for (auto& stop: stops){
      stops_to_buses[bus].push_back(stop);
      buses_to_stops[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
    BusesForStopResponse r;
    if (buses_to_stops.count(stop) == 0){
      r.msg.push_back("No stop");
      r.msg.push_back("\n");
    }
    else {
      for (const string& bus: buses_to_stops.at(stop))
        r.msg.push_back(bus + " ");
      r.msg.push_back("\n");
    }
    r.msg.pop_back();
    return r;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
    StopsForBusResponse r;
    if (stops_to_buses.count(bus) == 0){
      r.msg.push_back("No bus");
      r.msg.push_back("\n");
    }
    else{
      for (const string& stop: stops_to_buses.at(bus))
      {
        r.msg.push_back("Stop " + stop +": ");
        if (buses_to_stops.at(stop).size()==1)
          r.msg.push_back("no interchange");
        else
        {
          for (const string& other_bus: buses_to_stops.at(stop))
          {
            if (bus!=other_bus)
              r.msg.push_back(other_bus + " ");
          }
        }
        r.msg.push_back("\n");

      }
    }
    r.msg.pop_back();
    return r;
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
    AllBusesResponse r;
    if (stops_to_buses.empty()){
      r.msg.push_back("No buses");
      r.msg.push_back("\n");
    }
    else
    {
      for (const auto& [bus, stops]: stops_to_buses)
      {
        r.msg.push_back("Bus " + bus + ": ");
        for (const auto& stop: stops)
        {
          r.msg.push_back(stop + " ");
        }
        r.msg.push_back("\n");
      }
    }
    r.msg.pop_back();
    return r;
  }

private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
