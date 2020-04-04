#include <iostream>
#include <vector>

struct BusesForStopResponse {
  // Наполните полями эту структуру
  std::vector<std::string> msg;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  // Наполните полями эту структуру
  std::vector<std::string> msg;
  
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  // Наполните полями эту структуру
  std::vector<std::string> msg;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);