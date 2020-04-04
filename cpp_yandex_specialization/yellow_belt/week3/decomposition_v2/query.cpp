#include "query.h"


std::istream& operator>> (std::istream& is, Query& q) {
  // Реализуйте эту функцию
  std::string query_string;
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