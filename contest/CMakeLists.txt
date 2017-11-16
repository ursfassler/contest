cmake_minimum_required(VERSION 3.0.2)

project(contest_main)

set(CONTEST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")

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
