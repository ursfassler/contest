cmake_minimum_required(VERSION 3.0.2)

project("contest")

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

#this is a workaround because MSVC is a CMake internal variable which leads to confusion
#when doing STREQUAL on it
set(MSVC_COMPILER_NAME "MSVC")

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
if(CMAKE_CXX_COMPILER_ID STREQUAL ${MSVC_COMPILER_NAME})
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

set(GOOGLE_TEST_INCLUDE_DIR googletest/googletest/include)
set(GOOGLE_MOCK_INCLUDE_DIR googletest/googlemock/include)

add_subdirectory(googletest)


add_subdirectory(contest)
add_subdirectory(example)
