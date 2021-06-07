cmake_minimum_required(VERSION 3.10.2)
project(basic_algorithms_tree_RBTree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/RBTest.cpp)
target_link_libraries(${PROJECT_NAME} CS203_CATCH2_LIB)

#add_test(${PROJECT_NAME}_CTEST ${PROJECT_NAME})
