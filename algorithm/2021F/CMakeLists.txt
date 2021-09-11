cmake_minimum_required(VERSION 3.10.2)
set(YEAR 2021)
set(SEMESTER FALL)

project(CS203_DSAA_${YEAR}_${SEMESTER} LANGUAGES CXX)

enable_testing()
file(GLOB USER_LIBS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lab_*) # regex to find libs, more flexibility
foreach (elementName IN LISTS USER_LIBS_PATH)
    add_subdirectory(${elementName})
endforeach ()
unset(USER_LIBS_PATH)
