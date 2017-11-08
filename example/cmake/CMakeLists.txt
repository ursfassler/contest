cmake_minimum_required(VERSION 2.8)

project(contest_example_cmake)
add_executable(
    ${PROJECT_NAME}
    "unittest.cpp"
    )

#TARGET_LINK_LIBRARIES(${PROJECT_NAME} contest_main gmock)

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${PROJECT_NAME}
#)
