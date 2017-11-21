cmake_minimum_required(VERSION 2.8)

project(contest_example_cmake)


message(MESSAGE "INC: ${CONTEST_INCLUDE_DIR}")
add_executable(
    ${PROJECT_NAME}
    "example.cpp"
    )

add_executable("${PROJECT_NAME}_Tests" "unittest.cpp")
target_include_directories("${PROJECT_NAME}_Tests" PRIVATE ${GOOGLE_TEST_INCLUDE_DIR}
                                                   ${GOOLGE_MOCK_INCLUDE_DIR}
                                                   ${CONTEST_INCLUDE_DIR})
target_link_libraries("${PROJECT_NAME}_Tests" gmock gtest)


#TARGET_LINK_LIBRARIES(${PROJECT_NAME} contest_main gmock)

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${PROJECT_NAME}
#)
