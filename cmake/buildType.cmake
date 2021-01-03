if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_definitions(-DDEBUG)
elseif (${CMAKE_BUILD_TYPE} STREQUAL "Release")
endif ()
