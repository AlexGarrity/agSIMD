find_package(Threads REQUIRED)
include(ExternalProject)
include(GoogleTest)

ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/release-1.10.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(gtest source_dir binary_dir)

add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

if(WIN32)
    set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/lib/Debug/gtestd.lib"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")
else()
    set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/lib/libgtest.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")
endif(WIN32)

add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

if(WIN32)
    set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/lib/Debug/gmockd.lib"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")
else()
    set_target_properties(libgmock PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/lib/libgmock.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}")
endif(WIN32)

include_directories(
    "${source_dir}/googletest/include"
    "${source_dir}/googlemock/include"
)

if (${TEST_QUAD})
    add_subdirectory(TestQuad)
endif()

if (${TEST_MATH})
    add_subdirectory(TestMath)
endif()

if (${TEST_MATH_PACKED})
    add_subdirectory(TestPacked)
endif()