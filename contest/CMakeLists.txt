cmake_minimum_required(VERSION 2.8)

project(contest_main)
add_library(
    ${PROJECT_NAME} STATIC
    "main.cpp"
    )

install(
    TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    )

#TARGET_LINK_LIBRARIES(${PROJECT_NAME} gmock pthread)
#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${PROJECT_NAME}
#)
