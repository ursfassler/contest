cmake_minimum_required(VERSION 3.1)

project(contest_example_cmake)

find_package(tiny-tdd)

set(GOOGLE_TEST_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include)
set(GOOGLE_MOCK_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googlemock/include)
add_subdirectory(googletest)

add_executable(
    ${PROJECT_NAME}
    "example.cpp"
    )

add_executable("${PROJECT_NAME}_Tests" "unittest.cpp")
target_include_directories("${PROJECT_NAME}_Tests" PRIVATE ${GOOGLE_TEST_INCLUDE_DIR}
                                                   ${GOOLGE_MOCK_INCLUDE_DIR})
target_link_libraries("${PROJECT_NAME}_Tests" PRIVATE gmock gtest tiny-tdd)

enable_testing()
add_test(TARGET ${PROJECT_NAME} COMMAND "${PROJECT_NAME}_Tests")

#run the tests after building the main executable
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND "${PROJECT_NAME}_Tests"
)

# run the tests after building them
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND "${PROJECT_NAME}_Tests"
)

