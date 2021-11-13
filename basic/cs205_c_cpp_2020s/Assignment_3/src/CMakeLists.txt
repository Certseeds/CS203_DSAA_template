add_executable(${PROJECT_NAME}_01 ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_3_01.cpp)
add_executable(${PROJECT_NAME}_02 ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_3_02.cpp)
add_executable(${PROJECT_NAME}_03 ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_3_03.cpp)
add_executable(${PROJECT_NAME}_utf8_example ${CMAKE_CURRENT_SOURCE_DIR}/utf8_to_codepoint_example.cpp)

target_link_libraries(${PROJECT_NAME}_03 PUBLIC ${PROJECT_NAME}_utf8)
target_link_libraries(${PROJECT_NAME}_utf8_example PUBLIC ${PROJECT_NAME}_utf8)
