cmake_minimum_required(VERSION 3.12)
project(${PROJECT_NAME}_lab13_example)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}_main1
               ${CMAKE_CURRENT_SOURCE_DIR}/code1/main1.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/code1/circle.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/code1/circle.h
               ${CMAKE_CURRENT_SOURCE_DIR}/code1/rectangle.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/code1/rectangle.h)
add_executable(${PROJECT_NAME}_main2
               ${CMAKE_CURRENT_SOURCE_DIR}/code2/main2.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/code2/circle.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/code2/circle.h
               ${CMAKE_CURRENT_SOURCE_DIR}/code2/rectangle.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/code2/rectangle.h
               ${CMAKE_CURRENT_SOURCE_DIR}/code2/shape.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/code2/shape.h)
add_executable(${PROJECT_NAME}_main3
               ${CMAKE_CURRENT_SOURCE_DIR}/code3/main3.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/code3/circle.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/code3/circle.h
               ${CMAKE_CURRENT_SOURCE_DIR}/code3/rectangle.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/code3/rectangle.h
               ${CMAKE_CURRENT_SOURCE_DIR}/code3/shape.cpp)