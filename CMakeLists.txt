cmake_minimum_required(VERSION 3.1)

project("tiny-tdd")

add_library(
    ${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE 
    $<BUILD_INTERFACE:${tiny-tdd_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(${PROJECT_NAME} INTERFACE gmock gtest)


# installation properties follow below

install(TARGETS tiny-tdd EXPORT tinyTddTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
    )

install(EXPORT tinyTddTargets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE tiny-tdd::
    DESTINATION lib/cmake/tiny-tdd
)


include(CMakePackageConfigHelpers)
write_basic_package_version_file("tiny-tddConfigVersion.cmake" 
  VERSION 1.0.0 
  COMPATIBILITY SameMajorVersion)

install(FILES "tiny-tddConfig.cmake" "tiny-tddConfigVersion.cmake"
    DESTINATION lib/cmake/tiny-tdd)

