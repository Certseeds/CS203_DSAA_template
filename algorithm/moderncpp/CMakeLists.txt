cmake_minimum_required(VERSION 3.10.2)
project(${PROJECT_NAME}_moderncpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies 02 04 07)
foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName}
                   ${CMAKE_CURRENT_SOURCE_DIR}/chap${elementName}.cpp)
    # target_link_libraries(${PROJECT_NAME}_${elementName} CS203_CATCH2_LIB)
    target_link_libraries(${PROJECT_NAME}_${elementName} pthread)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName})
endforeach ()
unset(dependencies)