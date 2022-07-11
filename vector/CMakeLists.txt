cmake_minimum_required(VERSION 3.0.0)
project(vector VERSION 0.1.0)

enable_testing()

include_directories(../googletest/include)

add_executable(vector 
                main.cpp
                vector.h
                )

add_executable(test_vector test_vector.cpp)

target_link_libraries(test_vector PRIVATE gtest)


