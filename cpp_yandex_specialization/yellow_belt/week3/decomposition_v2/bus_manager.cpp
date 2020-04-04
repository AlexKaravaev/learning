#include "bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
  // Реализуйте этот метод
  for (auto& stop: stops){
    stops_to_buses[bus].push_back(stop);
    buses_to_stops[stop].push_back(bus);
  }
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
  // Реализуйте этот метод
  BusesForStopResponse r;
  if (buses_to_stops.count(stop) == 0){
    r.msg.push_back("No stop");
    r.msg.push_back("\n");
  }
  else {
    for (const std::string& bus: buses_to_stops.at(stop))
      r.msg.push_back(bus + " ");
    r.msg.push_back("\n");
  }
  r.msg.pop_back();
  return r;
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
  // Реализуйте этот метод
  StopsForBusResponse r;
  if (stops_to_buses.count(bus) == 0){
    r.msg.push_back("No bus");
    r.msg.push_back("\n");
  }
  else{
    for (const std::string& stop: stops_to_buses.at(bus))
    {
      r.msg.push_back("Stop " + stop +": ");
      if (buses_to_stops.at(stop).size()==1)
        r.msg.push_back("no interchange");
      else
      {
        for (const std::string& other_bus: buses_to_stops.at(stop))
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

AllBusesResponse BusManager::GetAllBuses() const {
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

