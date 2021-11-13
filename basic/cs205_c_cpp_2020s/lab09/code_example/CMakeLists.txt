cmake_minimum_required(VERSION 3.6)
project(${PROJECT_NAME}_lab09_example)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(example
               ./makefile/misc.c ./makefile/main.c
               )
