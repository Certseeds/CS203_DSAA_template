cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_tree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies traverse_test)

set(leetcode_order 94 95 96 98 100)
LIST(APPEND leetcode_order 104 226 530 559 589)
LIST(APPEND leetcode_order 590 617)
foreach (elementOrder IN LISTS leetcode_order)
    LIST(APPEND dependencies leetcode_${elementOrder})
endforeach ()
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
