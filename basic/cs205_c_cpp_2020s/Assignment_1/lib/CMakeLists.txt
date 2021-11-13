set(target_name ${PROJECT_NAME}_lib)

add_library(${target_name} ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/assignment_1.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/assignment_1.hpp
            )

target_include_directories(${target_name} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})