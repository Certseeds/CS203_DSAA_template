add_library(${PROJECT_NAME}_utf8
            ${LIB_WAY}
            utf8.cpp
            utf8.hpp)
set_source_files_properties(utf8.cpp PROPERTIES LANGUAGE CXX)

target_include_directories(${PROJECT_NAME}_utf8
                           INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR})

