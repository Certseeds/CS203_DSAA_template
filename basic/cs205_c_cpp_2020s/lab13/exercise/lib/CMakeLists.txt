add_library(${PROJECT_NAME}_CStereoShape
            ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/c_stereoShape_lab13_01.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/c_stereoShape_lab13_01.h)
add_library(${PROJECT_NAME}_CCube
            ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/c_cube_lab13_02.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/c_cube_lab13_02.h)
add_library(${PROJECT_NAME}_CSphere
            ${LIB_WAY}
            ${CMAKE_CURRENT_SOURCE_DIR}/c_sphere_lab13_03.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/c_sphere_lab13_03.h)

target_include_directories(${PROJECT_NAME}_CStereoShape
                           INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME}_CCube
                           INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME}_CSphere
                           INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}_CCube ${PROJECT_NAME}_CStereoShape)
target_link_libraries(${PROJECT_NAME}_CSphere ${PROJECT_NAME}_CStereoShape)

