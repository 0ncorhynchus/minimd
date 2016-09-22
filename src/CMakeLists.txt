file(GLOB HEADERS *.h)
file(GLOB SOURCES *.c)

add_library(minimd-core ${SOURCES})

install(FILES ${HEADERS} DESTINATION "include")
