cmake_minimum_required(VERSION 3.19)

#[===[ Basic Project Configuration ]===]

project("CPL"
    LANGUAGES CXX
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

enable_testing()

#[===[ Third-party dependencies ]===]

add_subdirectory("lib")

#[===[ Per-week Subdirectories ]===]

file(GLOB CPL_WEEKS
    RELATIVE "${PROJECT_SOURCE_DIR}"
    CONFIGURE_DEPENDS
    "week*/CMakeLists.txt"
)

foreach(WEEK IN LISTS CPL_WEEKS)
    get_filename_component(WEEK "${WEEK}" DIRECTORY)
    add_subdirectory("${WEEK}")
endforeach()
