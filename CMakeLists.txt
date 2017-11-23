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

# Prevent GoogleTest from overriding our compiler/linker options
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(GOOGLE_TEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include)
set(GOOGLE_MOCK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googlemock/include)
add_subdirectory(googletest)


#building context
set(CONTEST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories(${CONTEST_INCLUDE_DIR})
add_executable(
    ${PROJECT_NAME}
    "src/main.cpp"
    "include/ide_printer.h"
    )

target_include_directories(${PROJECT_NAME} PRIVATE ${GOOGLE_TEST_INCLUDE_DIR}
                                                   ${GOOLGE_MOCK_INCLUDE_DIR}
                                                   ${CONTEST_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} gmock gtest)

# adding example projects
add_subdirectory(example)
