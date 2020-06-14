cmake_minimum_required(VERSION 3.0.0)
project(final VERSION 0.1.0)

find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
file(GLOB SOURCE src/*.cpp)

include_directories("include")

#-------------------
# Test
#-------------------
enable_testing()
include_directories(${COMMON_INCLUDES})
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

add_subdirectory(tests)


add_executable(final main.cpp ${SOURCE})
add_compile_options(-Wall -Wextra -pedantic -Werror)