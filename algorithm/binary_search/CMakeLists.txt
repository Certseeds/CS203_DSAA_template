cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_binary_search LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(${PROJECT_NAME}_basic ${LIB_WAY} ${CMAKE_CURRENT_SOURCE_DIR}/basic.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/include/basic.hpp)
target_include_directories(${PROJECT_NAME}_basic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
set(dependencies basic_test triple_search rotate_array)

set(leetcode_order 35 4 33 162 34)
LIST(APPEND leetcode_order 69 81 153_154)
foreach (elementOrder IN LISTS leetcode_order)
    LIST(APPEND dependencies leetcode_${elementOrder})
endforeach ()
unset(leetcode_order)


foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE CS203_DSAA_TEST_MACRO)
    target_link_libraries(${PROJECT_NAME}_${elementName} PRIVATE
                          CS203_DSAA_template_INCLUDE
                          ${PROJECT_NAME}_basic)
    target_precompile_headers(${PROJECT_NAME}_${elementName} REUSE_FROM
                              CS203_DSAA_template_INCLUDE_PCH17
                              )
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)

