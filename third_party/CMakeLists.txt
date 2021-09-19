cmake_minimum_required(VERSION 3.16.6)
project(CS203_CATCH2_LIB VERSION 3.0.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/catch_amalgamated.cpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
if (LOCAL_MACHINE)
else ()
    target_precompile_headers(
            ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/catch_amalgamated.hpp
    )
endif ()