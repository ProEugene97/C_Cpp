cmake_minimum_required(VERSION 3.1)
project(Task1 C)

set(CMAKE_C_STANDARD 11)
add_executable(Task1 main.c)

project(Task1_tests)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(test/lib/googletest)
enable_testing()

include_directories(test/lib/googletest/googletest/include)

add_executable(Task1_tests test/test.cpp)
target_link_libraries(Task1_tests gtest gtest_main)
add_test( Task1_tests Task1_tests )