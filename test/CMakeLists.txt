FIND_PATH(CUNIT_INCLUDE_DIR NAMES CUnit/CUnit.h)
FIND_LIBRARY(CUNIT_LIBRARY NAMES cunit libcunit cunitlib)
include_directories(${CUNIT_INCLUDE_DIR})

add_subdirectory(minimd)
