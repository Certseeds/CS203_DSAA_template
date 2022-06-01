cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_array LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies)

set(leetcode_order 1 7 11 15 16)
list(APPEND leetcode_order 17 26 27 31 36)
list(APPEND leetcode_order 39 40 41 56 80)
list(APPEND leetcode_order 88 167 219 350 448)
list(APPEND leetcode_order 485 500 532 561 566)
list(APPEND leetcode_order 581 605 661 73 665)
list(APPEND leetcode_order 674 697 so_03 1020 717)
list(APPEND leetcode_order 724 240 so_21 so_45 so_61)
list(APPEND leetcode_order 747 766 1606 48 59)
list(APPEND leetcode_order 334 238 560 804 806)
list(APPEND leetcode_order 807 811 830 832 840)
list(APPEND leetcode_order 849 852 867 868 896)
list(APPEND leetcode_order 905 908 922)
LIST(TRANSFORM leetcode_order PREPEND leetcode_)

set(dependencies ${dependencies} ${leetcode_order})

unset(leetcode_order)

foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE CS203_DSAA_TEST_MACRO)
    target_link_libraries(${PROJECT_NAME}_${elementName} CS203_DSAA_template_INCLUDE)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)

