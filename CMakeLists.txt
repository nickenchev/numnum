cmake_minimum_required(VERSION 3.2)
project(numnum)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

add_executable(nn
  src/main.cpp)
