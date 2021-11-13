add_executable(${PROJECT_NAME}_test test_assignment_1.cpp)
target_link_libraries(${PROJECT_NAME}_test
                      PUBLIC
                      ${PROJECT_NAME}_lib
                      CS203_DSAA_template_INCLUDE)
