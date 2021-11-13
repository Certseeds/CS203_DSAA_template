add_library(${PROJECT_NAME}_utf8
            ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/utf8.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/utf8.hpp)

set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/utf8.cpp PROPERTIES LANGUAGE CXX)

target_include_directories(${PROJECT_NAME}_utf8
                           INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR})


add_library(${PROJECT_NAME} ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/UTF8string.cpp)

target_include_directories(${PROJECT_NAME}
                           INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_utf8)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_utf8)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})