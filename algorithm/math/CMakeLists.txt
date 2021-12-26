cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_math LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies min_max_middle)

set(leetcode_order 9 29 43 50 60)
LIST(APPEND leetcode_order 118_119 169 217 263)
LIST(APPEND leetcode_order 268 283 338 343 372)
LIST(APPEND leetcode_order 401 414 461)
foreach (elementOrder IN LISTS leetcode_order)
    LIST(APPEND dependencies leetcode_${elementOrder})
endforeach ()
unset(leetcode_order)

foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName} ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName} CS203_DSAA_template_INCLUDE)
    target_compile_definitions(${PROJECT_NAME}_${elementName} PRIVATE CS203_DSAA_TEST_MACRO)
    target_precompile_headers(${PROJECT_NAME}_${elementName} REUSE_FROM
                              CS203_DSAA_template_INCLUDE_PCH17
                              )
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)

