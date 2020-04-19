cmake_minimum_required(VERSION 3.0.0)
project(final VERSION 0.1.0)

find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)


include_directories("include")

#-------------------
# Test
#-------------------
enable_testing()
include_directories(${COMMON_INCLUDES})
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

# from list of files we'll create tests test_name.cpp -> test_name
foreach(_test_file ${TEST_SRC_FILES})
    get_filename_component(_test_name ${_test_file} NAME_WE)
    add_executable(${_test_name} ${_test_file})
    
    target_link_libraries(${_test_name} gtest gtest_main -lgtest ${CMAKE_THREAD_LIBS_INIT})
    add_test(${_test_name} ${_test_name})
    set_tests_properties(${_test_name} PROPERTIES TIMEOUT 5)
endforeach()


add_executable(final main.cpp src/database.cpp src/date.cpp)
add_compile_options(-Wall -Wextra -pedantic -Werror)