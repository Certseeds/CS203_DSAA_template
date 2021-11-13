cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_lab07_exercise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}_01 ${CMAKE_CURRENT_SOURCE_DIR}/lab07_01.cpp)
add_executable(${PROJECT_NAME}_02 ${CMAKE_CURRENT_SOURCE_DIR}/lab07_02.cpp)
add_executable(${PROJECT_NAME}_03 ${CMAKE_CURRENT_SOURCE_DIR}/lab07_03.cpp)
