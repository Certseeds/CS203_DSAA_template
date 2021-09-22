cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_INCLUDE LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)

set(dependencies include)
LIST(APPEND dependencies pch11)
LIST(APPEND dependencies pch17)
LIST(APPEND dependencies list)
LIST(APPEND dependencies tree)
LIST(APPEND dependencies magic_macro)
foreach (elementName IN LISTS dependencies)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${elementName})
endforeach ()
unset(dependencies)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} INTERFACE CS203_CATCH2_LIB ${PROJECT_NAME}_INCLUDE)

add_library(${PROJECT_NAME}_MULTIPLY INTERFACE)
if (MULTIPLY_TIMES)
    # 这一项为ON,此文件会多次编译,则打开预编译头文件,第一次编译时间增加(占有体积增加),换取之后编译速度提升
    # 倘若只编译一次,或更看重存储空间占用而非编译速度,可以改成OFF
    MESSAGE(STATUS "MULTIPLY_TIMES is ON")
    target_precompile_headers(${PROJECT_NAME}_MULTIPLY INTERFACE
                              ${CMAKE_CURRENT_SOURCE_DIR}/catch_main.hpp
                              )
else ()
    MESSAGE(STATUS "MULTIPLY_TIMES is OFF")
endif ()
