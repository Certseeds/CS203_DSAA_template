cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_list LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies 2 19 21 23 24)
LIST(APPEND dependencies 25 61 82 83 86)
LIST(APPEND dependencies 92)
foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/leetcode_${elementName}.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName} CS203_DSAA_template_INCLUDE CS203_DSAA_template_INCLUDE_LIST)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/leetcode_${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)

