cmake_minimum_required(VERSION 3.0.2)

project(contest_main)
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
