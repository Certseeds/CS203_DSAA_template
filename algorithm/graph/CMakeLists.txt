cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_graph LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(${PROJECT_NAME}_BUILD_GRAPH ${LIB_WAY} ${CMAKE_CURRENT_SOURCE_DIR}/build_graph.cpp)

enable_testing()
set(dependencies dijistra flow bfs dfs toposort)
LIST(TRANSFORM dependencies APPEND _test)

set(leetcode_order)
list(APPEND leetcode_order 743 so_12 so_13 797 1334)
LIST(TRANSFORM leetcode_order PREPEND leetcode_)

set(dependencies ${dependencies} ${leetcode_order})
foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName}_test
                   ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName}_test
                          ${PROJECT_NAME}_BUILD_GRAPH CS203_DSAA_template_INCLUDE)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName}_test from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName}_test)
endforeach ()
unset(dependencies)