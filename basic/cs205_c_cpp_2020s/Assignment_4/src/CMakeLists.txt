add_executable(${PROJECT_NAME}_01 ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_4_01.cpp)
add_executable(${PROJECT_NAME}_02 ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_4_02.cpp)
add_executable(${PROJECT_NAME}_03 ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_4_03.cpp)
add_executable(${PROJECT_NAME}_04 ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_4_04.cpp)
add_executable(${PROJECT_NAME}_05 ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_4_05.cpp)

target_link_libraries(${PROJECT_NAME}_01 PUBLIC ${PROJECT_NAME}_lib_1)
target_link_libraries(${PROJECT_NAME}_02 PUBLIC
                      ${PROJECT_NAME}_lib_1
                      ${PROJECT_NAME}_lib_2)
target_link_libraries(${PROJECT_NAME}_03 PUBLIC
                      ${PROJECT_NAME}_lib_1
                      ${PROJECT_NAME}_lib_2
                      ${PROJECT_NAME}_lib_3)
target_link_libraries(${PROJECT_NAME}_04 PUBLIC ${PROJECT_NAME}_lib_4)
target_link_libraries(${PROJECT_NAME}_05 PUBLIC ${PROJECT_NAME}_lib_5)
