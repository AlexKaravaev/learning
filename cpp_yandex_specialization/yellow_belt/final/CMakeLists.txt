cmake_minimum_required(VERSION 3.0.0)
project(final VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##################################
# Download and install GoogleTest

include(ExternalProject)
ExternalProject_Add(gtest
        URL https://github.com/google/googletest/archive/release-1.8.0.zip
        # Comment above line, and uncomment line below to use subversion.
        # SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
        # Uncomment line below to freeze a revision (here the one for 1.7.0)
        # SVN_REVISION -r700

        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        INSTALL_COMMAND ""
        )
ExternalProject_Get_Property(gtest source_dir binary_dir)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
file(GLOB SOURCE src/*.cpp)

include_directories("include")

#-------------------
# Test
#-------------------
add_executable(condition_parser_test  tests/condition_parser_test.cpp)
add_dependencies(condition_parser_test gtest)
target_link_libraries(condition_parser_test ${binary_dir}/libgtest.a)
target_link_libraries(condition_parser_test ${binary_dir}/libgtest_main.a)

enable_testing()
add_test (NAME condition_parser_test
          COMMAND condition_parser_test)

include_directories(${COMMON_INCLUDES})

add_executable(final main.cpp ${SOURCE})
add_compile_options(-Wall -Wextra -pedantic -Werror)