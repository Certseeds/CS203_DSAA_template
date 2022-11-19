cmake_minimum_required(VERSION 3.16.6)
project(CS203_CATCH2_LIB)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

Include(FetchContent)
set(CATCH2_URL https://github.com/catchorg/Catch2/archive/refs/tags/v3.2.0.tar.gz)
SET(CATCH2_HASH "e09b0a36ceca0cdb92a0197abe20ea01")
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    FetchContent_Declare(
            Catch2
            URL ${CATCH2_URL}
            URL_HASH MD5=${CATCH2_HASH}
            SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/catch2
    )
else()
    FetchContent_Declare(
            Catch2
            URL ${CATCH2_URL}
            URL_HASH MD5=${CATCH2_HASH}
            SOURCE_DIR  ${CMAKE_CURRENT_BINARY_DIR}/catch2
    )
endif ()
unset(CATCH2_URL)
FetchContent_MakeAvailable(Catch2)