cmake_minimum_required(VERSION 3.10.2)
project(basic_algorithms_graph LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(${PROJECT_NAME}_BUILD_GRAPH SHARED ${CMAKE_CURRENT_SOURCE_DIR}/build_graph.cpp)
add_library(${PROJECT_NAME}_dijistra SHARED ${CMAKE_CURRENT_SOURCE_DIR}/dijistra.cpp)
target_link_libraries(${PROJECT_NAME}_dijistra ${PROJECT_NAME}_BUILD_GRAPH)

enable_testing()
set(dependencies test_dijistra)
foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName} ${PROJECT_NAME}_dijistra)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)