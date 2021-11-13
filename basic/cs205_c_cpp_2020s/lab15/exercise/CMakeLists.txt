cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_lab15_exercise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(${PROJECT_NAME}
               ${CMAKE_CURRENT_SOURCE_DIR}/lab15_01.cpp
               )
