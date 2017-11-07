cmake_minimum_required(VERSION 3.0.2)

project(contest_main)

#this is a workaround because MSVC is a CMake internal variable which leads to confusion
#when doing STREQUAL on it
set(MSVC_COMPILER_NAME "MSVC")

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
if(CMAKE_CXX_COMPILER_ID STREQUAL ${MSVC_COMPILER_NAME})
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

add_subdirectory(googletest)

add_executable(
    ${PROJECT_NAME}
    "main.cpp"
    )

target_include_directories(${PROJECT_NAME} PRIVATE googletest/googletest/include
                                                   googletest/googlemock/include )
target_link_libraries(${PROJECT_NAME} gmock gtest)


#TARGET_LINK_LIBRARIES(${PROJECT_NAME} gmock pthread)
#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${PROJECT_NAME}
#)
