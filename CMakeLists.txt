cmake_minimum_required(VERSION 3.0.0)
project(cmake_test_project VERSION 0.1.0)
add_executable(cmake_test_project main.cpp)

enable_testing()

add_subdirectory(googletest)

include_directories(googletest/include)

add_executable(test_array test_array.cpp)

target_link_libraries(test_array PRIVATE gtest)

add_subdirectory(vector)
add_subdirectory(string)

SET(CMAKE_CXX_FLAGS "-g -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")