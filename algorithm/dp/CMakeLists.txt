cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_dp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()


enable_testing()
set(dependencies)

set(leetcode_order 1143 5 10 44 45)
LIST(APPEND leetcode_order 63 62 64 70_746)
LIST(APPEND leetcode_order 97 322 509_1137 416)
LIST(APPEND leetcode_order 198)
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

