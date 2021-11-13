add_executable(${PROJECT_NAME}_test ${CMAKE_CURRENT_SOURCE_DIR}/test_assignment_2.cpp)
target_link_libraries(${PROJECT_NAME}_test
                      PUBLIC
                      ${PROJECT_NAME}_lib
                      CS203_DSAA_template_INCLUDE)

