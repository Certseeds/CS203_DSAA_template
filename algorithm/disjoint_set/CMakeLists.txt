cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_disjoint_set LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(${PROJECT_NAME}_lib ${LIB_WAY} ${CMAKE_CURRENT_SOURCE_DIR}/disjoint_set.cpp)
target_link_libraries(${PROJECT_NAME}_lib PRIVATE CS203_DSAA_template_INCLUDE)

enable_testing()
set(dependencies 684 200 130 399)
foreach (elementOrder IN LISTS dependencies)
    set(elementName leetcode_${elementOrder})
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName} ${PROJECT_NAME}_lib CS203_DSAA_template_INCLUDE)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
    unset(elementName)
endforeach ()
unset(dependencies)



