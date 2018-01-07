cmake_minimum_required(VERSION 3.1)

project("tiny-tdd")

# Prevent GoogleTest from overriding our compiler/linker options
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_library(
    ${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)

target_link_libraries(${PROJECT_NAME} INTERFACE gmock gtest)

set_target_properties(${PROJECt_NAME} PROPERTIES INTERFACE_INCLUDE_DIRECTORIES include)