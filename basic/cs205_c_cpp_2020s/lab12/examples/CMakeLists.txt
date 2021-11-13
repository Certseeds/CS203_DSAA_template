cmake_minimum_required(VERSION 3.6)
project(${PROJECT_NAME}_lab12_example)

set(CMAKE_CXX_STANDARD 17)

set(List 0 1 2 3 4)
foreach (element IN LISTS List)
    add_executable(${PROJECT_NAME}_example${element}
                   ${CMAKE_CURRENT_SOURCE_DIR}/use_complex${element}.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/complex${element}.cpp
                   )
endforeach ()
unset(List)