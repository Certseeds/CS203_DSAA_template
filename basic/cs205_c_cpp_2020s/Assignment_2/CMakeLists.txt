cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_Assignment_2 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(_List lib src test)
foreach (element IN LISTS _List)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${element})
endforeach ()
unset(_List)
