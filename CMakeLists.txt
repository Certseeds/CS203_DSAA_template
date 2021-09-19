cmake_minimum_required(VERSION 3.16.6)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 2)
set(PROJECT_VERSION_PATCH 2)
project(CS203_DSAA_template
        VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
        LANGUAGES CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(LOCAL_MACHINE OFF) # 这一项为ON,则为本地主机,则打开预编译头文件,第一次编译时间增加(占有体积增加),换取之后编译速度提升
# 倘若更看重存储空间占用而非编译速度,可以改成OFF

string(TIMESTAMP time_str "%Y/%m/%d  %y:%m:%S")
MESSAGE(STATUS "Compiler In \n ${time_str}")
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CMakeLists.txt)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/algorithm)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party)

enable_testing()
file(GLOB USER_LIBS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lab_*) # regex to find libs, more flexibility
foreach (elementName IN LISTS USER_LIBS_PATH)
    add_subdirectory(${elementName})
endforeach ()
unset(USER_LIBS_PATH)
