cmake_minimum_required(VERSION 3.6)
project (Test-Project CXX)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(SOURCE_FILES main.cpp list/single_linked_list.hpp list/linked_list.hpp)

add_executable(Test-Project ${SOURCE_FILES})
