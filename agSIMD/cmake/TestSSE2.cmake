
function(TestSSE2)
    message(STATUS "Checking for SSE2 support")

    message(DEBUG "Auto-detecting compiler flag")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        message(DEBUG "Compiler ID is \"GNU\".  Using -msse2")
        set(EXTENSION_FLAG -msse2)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        message(DEBUG "Compiler ID is \"Clang\".  Using -msse2")
        set(EXTENSION_FLAG -msse2)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        message(DEBUG "Compiler ID is \"MSVC\".  Using /arch:SSE2")
        set(EXTENSION_FLAG /arch:SSE2)
    else()
        message(FATAL_ERROR "Extensions are unsupported on this compiler.  Please use GNU, Clang, or MSVC")
    endif()

    try_run(
        EXIT_CODE COMPILE_CODE ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/SSE2.cpp
        COMPILE_DEFINITIONS ${EXTENSION_FLAG}
    )
    
    message(DEBUG "SSE2 support returned ${EXIT_CODE}")
    set(SSE2_FLAG ${EXTENSION_FLAG} CACHE INTERNAL "The flag required to complile SSE2" FORCE)
    set(HAS_SSE2 ${EXIT_CODE} CACHE INTERNAL "Does the system has SSE2?" FORCE)
endfunction()