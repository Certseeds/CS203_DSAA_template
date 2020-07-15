cmake_minimum_required(VERSION 3.10.2)
project(CS203_DSAA_template)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O0")


set(lab_number 00)
set(problem_order A)

include_directories(./includes)
include_directories(./source/lab_${lab_number})
include_directories(./test/lab_${lab_number})

add_executable(${PROJECT_NAME}
        ./source/lab_${lab_number}/lab_${lab_number}_${problem_order}.cpp)

add_executable(${PROJECT_NAME}_test
        ./includes/catch_main.hpp
        ./test/lab_${lab_number}/lab_${lab_number}_${problem_order}_test.cpp)
