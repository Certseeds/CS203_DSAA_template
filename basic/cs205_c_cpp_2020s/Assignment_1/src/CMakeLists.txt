add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/assignment_1_main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}_lib)