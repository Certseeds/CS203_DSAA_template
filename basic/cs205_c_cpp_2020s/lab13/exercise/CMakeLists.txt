cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_lab13_exercise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_subdirectory(lib)

add_executable(${PROJECT_NAME}_01 ${CMAKE_CURRENT_SOURCE_DIR}/lab13_01.cpp)
add_executable(${PROJECT_NAME}_02 ${CMAKE_CURRENT_SOURCE_DIR}/lab13_02.cpp)
add_executable(${PROJECT_NAME}_04 ${CMAKE_CURRENT_SOURCE_DIR}/lab13_04.cpp)


target_link_libraries(${PROJECT_NAME}_01 ${PROJECT_NAME}_CStereoShape)
target_link_libraries(${PROJECT_NAME}_02 ${PROJECT_NAME}_CCube)
target_link_libraries(${PROJECT_NAME}_04
                      ${PROJECT_NAME}_CCube
                      ${PROJECT_NAME}_CSphere)