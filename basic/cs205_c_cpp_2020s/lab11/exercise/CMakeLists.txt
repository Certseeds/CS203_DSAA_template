cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_lab11_exercise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_subdirectory(lib)

add_executable(${PROJECT_NAME}_01 ${CMAKE_CURRENT_SOURCE_DIR}/lab11_01.cpp)
target_link_libraries(${PROJECT_NAME}_01 ${PROJECT_NAME}_CandyBar)

add_executable(${PROJECT_NAME}_02 ${CMAKE_CURRENT_SOURCE_DIR}/lab11_02.cpp)
target_link_libraries(${PROJECT_NAME}_02 ${PROJECT_NAME}_Rectangle)
