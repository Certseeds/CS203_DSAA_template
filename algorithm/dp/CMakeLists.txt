cmake_minimum_required(VERSION 3.10.2)
project(basic_algorithms_dp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(${PROJECT_NAME}_TEST ${CMAKE_CURRENT_SOURCE_DIR}/dp_test.cpp)
enable_testing()
set(dependencies lcs_1143)
foreach (elementName IN LISTS dependencies)
    add_library(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    target_link_libraries(${PROJECT_NAME}_TEST ${PROJECT_NAME}_${elementName})
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
endforeach ()
unset(dependencies)

add_test(${PROJECT_NAME}_CTEST ${PROJECT_NAME}_TEST)
