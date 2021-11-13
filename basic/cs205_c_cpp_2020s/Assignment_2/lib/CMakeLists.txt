set(target_name_city ${PROJECT_NAME}_lib_city)

add_library(${target_name_city} ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/city.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/city.hpp)

target_include_directories(${target_name_city}
                           INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR})

set(target_name ${PROJECT_NAME}_lib)

add_library(${target_name} ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_2.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_2.hpp)

target_include_directories(${target_name}
                           INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${target_name} PUBLIC ${target_name_city})
target_include_directories(${target_name} PUBLIC ${target_name_city})

unset(${target_name})
unset(${target_name_city})
