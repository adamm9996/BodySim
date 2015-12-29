cmake_minimum_required(VERSION 3.3)
project(BodySim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/display.cpp src/display.h src/body.cpp src/body.h src/simulation.cpp src/simulation.h)
add_executable(BodySim ${SOURCE_FILES})