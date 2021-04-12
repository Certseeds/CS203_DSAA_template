cmake_minimum_required(VERSION 3.10.2)
project(basic_algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies dp sort tree binary_search string_search graph)
foreach (elementName IN LISTS dependencies)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${elementName})
endforeach ()
unset(dependencies)
