cmake_minimum_required(VERSION 3.16.6)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 8)
set(PROJECT_VERSION_PATCH 0)
project(CS203_DSAA_template
        VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
        DESCRIPTION "Template for Algorithm Based on C++11 and Modern CMake"
        HOMEPAGE_URL "https://github.com/Certseeds/CS203_DSAA_template"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)
option(MULTIPLY_TIMES "This is a option for pre compile headers" ON) # 加速效果大约有1/3, 3s -> 2s左右

#string(TIMESTAMP time_str "%Y/%m/%d  %H:%M:%S")
#MESSAGE(STATUS "Compiler In \n ${time_str}")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CMakeLists.txt)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/algorithm)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/basic)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party)

enable_testing()
file(GLOB USER_LIBS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lab_*) # regex to find libs, more flexibility
foreach (elementName IN LISTS USER_LIBS_PATH)
    add_subdirectory(${elementName})
endforeach ()
unset(USER_LIBS_PATH)
