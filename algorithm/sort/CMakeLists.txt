cmake_minimum_required(VERSION 3.10.2)
project(basic_algorithms_sort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
add_executable(${PROJECT_NAME}
        #./insert_sort.cpp
        #./bubble_sort.cpp
        #./selection_sort.cpp
        #./merge_sort.cpp
        ./heap_sort.cpp
        #./quick_sort.cpp
        ./sort_test.cpp
        )