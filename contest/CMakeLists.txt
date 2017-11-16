cmake_minimum_required(VERSION 3.0.2)

project(contest_main)

set(CONTEST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")

#this is a workaround because MSVC is a CMake internal variable which leads to confusion
#when doing STREQUAL on it
set(MSVC_COMPILER_NAME "MSVC")

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
if(CMAKE_CXX_COMPILER_ID STREQUAL ${MSVC_COMPILER_NAME})
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

add_executable(
    ${PROJECT_NAME}
    "main.cpp" "ide_printer.h"
    )

target_include_directories(${PROJECT_NAME} PRIVATE ${GOOGLE_TEST_INCLUDE_DIR}
                                                   ${GOOLGE_MOCK_INCLUDE_DIR} )
target_link_libraries(${PROJECT_NAME} gmock gtest)


#TARGET_LINK_LIBRARIES(${PROJECT_NAME} gmock pthread)
#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${PROJECT_NAME}
#)
