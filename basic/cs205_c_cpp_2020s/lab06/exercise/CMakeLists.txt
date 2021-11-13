cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_lab06_exercise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME}_01
               lab06_02.cpp)
add_executable(${PROJECT_NAME}_02
               lab06_02.cpp)
add_executable(${PROJECT_NAME}_03
               lab06_03.cpp)
add_executable(${PROJECT_NAME}_read_books read_books.cpp)

target_link_libraries(${PROJECT_NAME}_read_books ${PROJECT_NAME}_Book)

