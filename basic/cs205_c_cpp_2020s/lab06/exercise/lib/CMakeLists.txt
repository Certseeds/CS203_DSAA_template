add_library(${PROJECT_NAME}_Book
            ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/Book.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Book.cpp)
target_include_directories(${PROJECT_NAME}_Book
                           INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR})