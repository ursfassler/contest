cmake_minimum_required(VERSION 2.8)

project(contest_example_cmake)

#this is a workaround because MSVC is a CMake internal variable which leads to confusion
#when doing STREQUAL on it
set(MSVC_COMPILER_NAME "MSVC")

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
if(CMAKE_CXX_COMPILER_ID STREQUAL ${MSVC_COMPILER_NAME})
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

message(MESSAGE "INC: ${CONTEST_INCLUDE_DIR}")
add_executable(
    ${PROJECT_NAME}
    "unittest.cpp"
    )
target_include_directories(${PROJECT_NAME} PRIVATE ${GOOGLE_TEST_INCLUDE_DIR}
                                                   ${GOOLGE_MOCK_INCLUDE_DIR}
                                                   ${CONTEST_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} gmock gtest)


#TARGET_LINK_LIBRARIES(${PROJECT_NAME} contest_main gmock)

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${PROJECT_NAME}
#)
