cmake_minimum_required(VERSION 3.6)
project(CStructures)
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")

enable_testing()

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(list)
add_subdirectory(test)
