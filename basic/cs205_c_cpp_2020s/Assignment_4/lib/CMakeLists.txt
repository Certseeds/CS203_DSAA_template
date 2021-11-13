set(_List 1 2 3 4 5)
foreach (element IN LISTS _List)
    add_library(${PROJECT_NAME}_lib_${element}
                ${LIB_WAY}
                ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_4_0${element}.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/Assignment_4_0${element}.hpp)
    target_include_directories(${PROJECT_NAME}_lib_${element}
                               INTERFACE
                               ${CMAKE_CURRENT_SOURCE_DIR})
endforeach ()
unset(_List)