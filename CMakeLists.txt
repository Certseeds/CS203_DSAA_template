cmake_minimum_required(VERSION 3.10.2)
project(CS203_DSAA_template)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/cross_platform.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/parallel.cmake)
string(TIMESTAMP time_str "%Y/%m/%d  %y:%m:%S")
MESSAGE(STATUS "Compiler In \n ${time_str}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/algorithm)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party)

enable_testing()
file(GLOB USER_LIBS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lab_*) # regex to find libs, more flexibility
foreach(elementName IN LISTS USER_LIBS_PATH)
    add_subdirectory(${elementName})
endforeach()
unset(USER_LIBS_PATH)
