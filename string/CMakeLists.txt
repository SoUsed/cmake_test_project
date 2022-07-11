cmake_minimum_required(VERSION 3.0.0)
project(stringproj VERSION 0.1.0)

enable_testing()

include_directories(../googletest/include)
include_directories(../vector)

add_executable(stringproj
                main.cpp
                mystring.h
                )

add_executable(test_string test_string.cpp)

target_link_libraries(test_string PRIVATE gtest)


