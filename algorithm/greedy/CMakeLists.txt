cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_greedy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies 1353)
LIST(TRANSFORM dependencies PREPEND leetcode_)

foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE CS203_DSAA_TEST_MACRO)
    target_link_libraries(${PROJECT_NAME}_${elementName} CS203_DSAA_template_INCLUDE)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
    unset(elementName)
endforeach ()
unset(dependencies)

