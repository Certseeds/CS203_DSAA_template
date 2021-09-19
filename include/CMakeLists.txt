cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_INCLUDE LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)

set(dependencies include)
LIST(APPEND dependencies list)
LIST(APPEND dependencies tree)
LIST(APPEND dependencies magic_macro)
foreach (elementName IN LISTS dependencies)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${elementName})
endforeach ()
unset(dependencies)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} INTERFACE CS203_CATCH2_LIB ${PROJECT_NAME}_INCLUDE)

