cmake_minimum_required(VERSION 3.10.2)
project(${PROJECT_NAME}_graph LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(${PROJECT_NAME}_BUILD_GRAPH ${LIB_WAY} ${CMAKE_CURRENT_SOURCE_DIR}/build_graph.cpp)
target_include_directories(${PROJECT_NAME}_BUILD_GRAPH PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
set(dependencies dijistra flow)
foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName}
                   ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_test.cpp
                   ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName} ${PROJECT_NAME}_BUILD_GRAPH CS203_CATCH2_LIB)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)