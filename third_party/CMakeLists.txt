cmake_minimum_required(VERSION 3.16.6)
project(CS203_CATCH2_LIB VERSION 3.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_library(${PROJECT_NAME} ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/catch_amalgamated.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
