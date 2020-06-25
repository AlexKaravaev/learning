cmake_minimum_required(VERSION 3.3)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES sort_by.cpp airline_ticket.h test_runner.h)
add_executable(sort ${SOURCE_FILES})