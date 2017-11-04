cmake_minimum_required (VERSION 2.6)
project (Neuron)

enable_testing()
add_subdirectory(googletest)
include_directories(${GTEST_INCLUDE_DIRS}/ ${gtest_SOURCE_DIR})

set (CMAKE_CXX_FLAGS " -W -Wall -pedantic -std=c++11")
add_executable (neuron main.cpp neuron.cpp network.cpp)

add_executable(runGtest unittest.cpp neuron.cpp network.cpp)
target_link_libraries(runGtest gtest gtest_main)
add_test(runGtest runGtest)
