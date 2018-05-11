cmake_minimum_required(VERSION 3.2)
project(numnum)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

find_package(Boost 1.67 COMPONENTS program_options)
if (Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(nn src/main.cpp)
  target_link_libraries(nn ${Boost_LIBRARIES})
endif()

