cmake_minimum_required(VERSION 3.16.6)
project(${PROJECT_NAME}_disk_schedule LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

enable_testing()
set(dependencies fcfs sstf scan cscan look clook)
foreach (elementName IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${elementName}_test ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_schedule_disk.cpp)
    target_link_libraries(${PROJECT_NAME}_${elementName}_test CS203_DSAA_template_INCLUDE)
    target_compile_definitions(${PROJECT_NAME}_${elementName}_test PRIVATE CS203_DSAA_TEST_MACRO)
    MESSAGE(STATUS "${PROJECT_NAME}_${elementName} from ${CMAKE_CURRENT_SOURCE_DIR}/${elementName}_schedule_disk.cpp")
    add_test(${PROJECT_NAME}_${elementName}_CTEST ${PROJECT_NAME}_${elementName}_test)
endforeach ()
unset(dependencies)