#include "responses.h"

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
  for (auto& msg_part: r.msg)
    os << msg_part;
  return os;
}

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  for (auto& msg_part: r.msg)
    os << msg_part;
  return os;
}

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  for (auto& msg_part: r.msg)
    os << msg_part;
  return os;
}