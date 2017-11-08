cmake_minimum_required(VERSION 3.1)

project("contest")

set(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
    message("Setting archive output directory to ${CMAKE_BINARY_DIR}/lib")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

if(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
    message("Setting library output directory to ${CMAKE_BINARY_DIR}/lib")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

if(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    message("Setting runtime output directory to ${CMAKE_BINARY_DIR}/bin")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()


add_subdirectory(contest)
add_subdirectory(example)
