cmake_minimum_required(VERSION 2.8)

project(contest_example_cmake)


add_executable(
    ${PROJECT_NAME}
    "example.cpp"
    )

add_executable("${PROJECT_NAME}_Tests" "unittest.cpp" "${CONTEST_INCLUDE_DIR}/ide_printer.h")
target_include_directories("${PROJECT_NAME}_Tests" PRIVATE ${GOOGLE_TEST_INCLUDE_DIR}
                                                   ${GOOLGE_MOCK_INCLUDE_DIR}
                                                   ${CONTEST_INCLUDE_DIR})
target_link_libraries("${PROJECT_NAME}_Tests" gmock gtest)

enable_testing()
add_test(TARGET ${PROJECT_NAME} COMMAND "${PROJECT_NAME}_Tests")

#TARGET_LINK_LIBRARIES(${PROJECT_NAME} contest_main gmock)

#run the tests after building the main executable
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND "${PROJECT_NAME}_Tests"
)

# run the tests after building them
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND "${PROJECT_NAME}_Tests"
)

