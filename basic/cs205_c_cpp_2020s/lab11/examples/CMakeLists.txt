cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_lab11_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME}_BOX ${LIB_WAY} ${CMAKE_CURRENT_SOURCE_DIR}/box.cpp)

set(List 1 2 3 4)
foreach (element IN LISTS List)
    add_executable(${PROJECT_NAME}_TestBox${element} ${CMAKE_CURRENT_SOURCE_DIR}/test_box${element}.cpp)
    target_link_libraries(${PROJECT_NAME}_TestBox${element} PUBLIC ${PROJECT_NAME}_BOX)
endforeach ()
unset(List)

add_executable(${PROJECT_NAME}_structvsclass ${CMAKE_CURRENT_SOURCE_DIR}/structvsclass.cpp)
