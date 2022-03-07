cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_tree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies traverse_test huffman_test)

set(leetcode_order 94 95 96 98 100)
LIST(APPEND leetcode_order 104 226 530 559 589)
LIST(APPEND leetcode_order 590 617 654 669 700)
LIST(APPEND leetcode_order 701 144 145 102 101)
LIST(APPEND leetcode_order 112 235 653 so_32 so_26)
LIST(APPEND leetcode_order 113 426 so_54 114 230)
LIST(APPEND leetcode_order 236 543)
LIST(TRANSFORM leetcode_order PREPEND leetcode_)

set(dependencies ${dependencies} ${leetcode_order})

unset(leetcode_order)

foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName}
                   ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName}
                          CS203_DSAA_template_INCLUDE)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/RBTree)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/avl)
