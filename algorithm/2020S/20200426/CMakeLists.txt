cmake_minimum_required(VERSION 3.16.6)
set(PROJECT_DAY 20200426)
project(${PROJECT_NAME}_${PROJECT_DAY})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")


set(dependencies "1st" "3rd" "4th" "5th")
foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${PROJECT_DAY}_${elementName}
                   ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_DAY}_${elementName}.cpp)
endforeach ()
