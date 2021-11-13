cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_Assignment_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(_List lib src)
foreach (element IN LISTS _List)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${element})
endforeach ()
unset(_List)
