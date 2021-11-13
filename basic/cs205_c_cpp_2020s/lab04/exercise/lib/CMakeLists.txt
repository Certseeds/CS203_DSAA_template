add_library(${PROJECT_NAME}_CandyBar ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/CandyBar.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/CandyBar.cpp)
target_include_directories(${PROJECT_NAME}_CandyBar INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME}_pizza ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/pizza.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/pizza.cpp)
target_include_directories(${PROJECT_NAME}_pizza INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(lab04)