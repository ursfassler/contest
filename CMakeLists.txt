cmake_minimum_required(VERSION 3.1)

project("contest")

set(CMAKE_CXX_STANDARD 11)

#configure and download google test at configure time. 
configure_file(DownloadGoogleTest.cmake.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

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

set(GOOGLE_TEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include)
set(GOOGLE_MOCK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googlemock/include)


add_subdirectory(contest)
add_subdirectory(example)
