cmake_minimum_required(VERSION 3.14.5)
PROJECT(${PROJECT_NAME}_lab10_opencv_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
if (OpenCV_FOUND)
    #add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lab10/examples)
    MESSAGE(STATUS "lab10 using libopencv-dev")
    add_executable(${PROJECT_NAME}_main_test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    target_link_libraries(${PROJECT_NAME}_main_test ${OpenCV_LIBS})

    add_executable(${PROJECT_NAME}_line_detection ${CMAKE_CURRENT_SOURCE_DIR}/line_detection.cpp)
    target_link_libraries(${PROJECT_NAME}_line_detection ${OpenCV_LIBS})

    add_executable(${PROJECT_NAME}_detect_circles ${CMAKE_CURRENT_SOURCE_DIR}/detect_circles.cpp)
    target_link_libraries(${PROJECT_NAME}_detect_circles ${OpenCV_LIBS})

    add_executable(${PROJECT_NAME}_detect_face ${CMAKE_CURRENT_SOURCE_DIR}/detect_face.cpp)
    target_link_libraries(${PROJECT_NAME}_detect_face ${OpenCV_LIBS})
endif ()
