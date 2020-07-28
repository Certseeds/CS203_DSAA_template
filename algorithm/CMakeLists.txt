cmake_minimum_required(VERSION 3.10.2)
project(basic_algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_subdirectory(./sort)

add_subdirectory(./binary_search)
