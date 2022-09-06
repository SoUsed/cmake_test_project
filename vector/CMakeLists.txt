cmake_minimum_required(VERSION 3.0.0)
project(vector VERSION 0.1.0)

enable_testing()

set(MY_LIBRARY_SRC vector.h vector.cpp)
add_library(MY_LIBRARY STATIC ${MY_LIBRARY_SRC})

include_directories(../googletest/include)
include_directories(./)

add_executable(vector 
                main.cpp
                vector.h
                )

SET(TARGET_SRC
    vector.cpp)

add_executable(test_vector test_vector.cpp)

target_link_libraries(test_vector PUBLIC MY_LIBRARY)
target_link_libraries(vector PUBLIC MY_LIBRARY)
target_link_libraries(test_vector PRIVATE gtest)

SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")