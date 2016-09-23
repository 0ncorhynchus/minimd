file(GLOB SOURCES *.c)
foreach(SOURCE ${SOURCES})
    get_filename_component(TEST_NAME ${SOURCE} NAME_WE)
    add_executable(${TEST_NAME} ${SOURCE})
    target_link_libraries(${TEST_NAME}
        minimd ${CUNIT_LIBRARY})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
