file(GLOB HEADERS *.h)
file(GLOB SOURCES *.c)

add_library(minimd-forcefield ${SOURCES})
install(FILES ${HEADERS} DESTINATION "include/minimd/forcefield")
