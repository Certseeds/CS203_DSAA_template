function(CMAKE_CMP_0135)
    # Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
    if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
        cmake_policy(SET CMP0135 NEW)
        MESSAGE("CMP0135 SET TO NEW")
    endif ()
endfunction()

