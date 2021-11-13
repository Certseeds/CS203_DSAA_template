# header begin
cmake_minimum_required(VERSION 3.16.6)
project(CS205_C_CPP_2020S LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

include(${CMAKE_SOURCE_DIR}/cmake/cross_platform.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/parallel.cmake)

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/include.cmake)
enable_testing()
set(exerciseList 01 02 03 04 05 06 07 08 09 11 12 13 14 15) #)
Add_Sub_Dir_List(exerciseList lab /exercise)
unset(exerciseList)

set(examplesList 06 07 08 10 11 12 13)
Add_Sub_Dir_List(examplesList lab /examples)
unset(examplesList)
#
set(AssignmentList 1 2 3 4 5)
Add_Sub_Dir_List(AssignmentList Assignment_ "")
unset(AssignmentList)

add_subdirectory(midterm)


#add_subdirectory(CS205_project_2020S)
