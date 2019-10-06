cmake_minimum_required(VERSION 3.15)
project(Task1_tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)

add_executable(Task1_tests test.cpp)
target_link_libraries(Task1_tests gtest)