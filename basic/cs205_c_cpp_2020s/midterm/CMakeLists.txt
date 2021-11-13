cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_Midterm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(_List 1 2 4)
foreach (element IN LISTS _List)
    add_executable(${PROJECT_NAME}_0${element}
                   ${CMAKE_CURRENT_SOURCE_DIR}/question${element}.cpp)
endforeach ()
unset(_List)

add_subdirectory(2021Spring)