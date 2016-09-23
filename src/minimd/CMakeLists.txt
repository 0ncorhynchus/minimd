file(GLOB HEADERS *.h)
file(GLOB SOURCES *.c)

add_library(minimd ${SOURCES})
install(FILES ${HEADERS} DESTINATION "include/minimd")

add_subdirectory(forcefield)

target_link_libraries(minimd minimd-forcefield)
