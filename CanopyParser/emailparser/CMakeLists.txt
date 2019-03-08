cmake_minimum_required(VERSION 3.12)
project(emailparser)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(emailparser main.cpp)