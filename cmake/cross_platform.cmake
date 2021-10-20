set(USE_OPENCV False)
IF (WIN32)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
    set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /Wall /GR /EHsc" CACHE INTERNAL "")
    MESSAGE(WARNING "WIN32's MSVC will make the output change-line symbol to \\r\\n, which make files comp fail")
    set(LIB_WAY STATIC)
    MESSAGE(WARNING "Under Windows Shared Lib Need add some other thing, so use STATIC lib \n STATIC cost much more space compare with shared lib")
ELSEIF (APPLE)
    set(LIB_WAY SHARED)
    MESSAGE(STATUS "Now is MacOS.")
ELSEIF (UNIX)
    set(LIB_WAY SHARED)
    set(USE_OPENCV true)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
    MESSAGE(STATUS "Now is UNIX-like OS's. Including Apple os x and CygWin")
ENDIF ()
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED) # instead of pthread

MESSAGE(STATUS ${CMAKE_CURRENT_SOURCE_DIR}/cross_platform.cmake)