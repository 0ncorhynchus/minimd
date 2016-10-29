add_subdirectory(minimd)

set(EXECUTABLE main)
add_executable(${EXECUTABLE} main.c)
target_link_libraries(${EXECUTABLE} minimd)
