cmake_minimum_required(VERSION 3.0.0)
project(stringproj VERSION 0.1.0)

include_directories(../vector)

enable_testing()

set(MY_LIBRARY_SRC mystring.h mystring.cpp)
add_library(MY_LIBRARY_STR STATIC ${MY_LIBRARY_SRC})


include_directories(../googletest/include)

add_executable(stringproj
                main.cpp
                )

SET(TARGET_SRC
    mystring.cpp)

add_executable(test_string test_string.cpp)

target_link_libraries(test_string PUBLIC MY_LIBRARY)
target_link_libraries(stringproj PUBLIC MY_LIBRARY)

target_link_libraries(test_string PUBLIC MY_LIBRARY_STR)
target_link_libraries(stringproj PUBLIC MY_LIBRARY_STR)

target_link_libraries(test_string PRIVATE gtest)

SET(CMAKE_CXX_FLAGS "-g -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")