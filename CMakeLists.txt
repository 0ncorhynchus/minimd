cmake_minimum_required (VERSION 2.8)
enable_testing()

project (minimd)
add_definitions("-std=c99")

include_directories(${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(test)
