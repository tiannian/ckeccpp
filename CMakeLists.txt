PROJECT(ckeccpp)

CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

INCLUDE_DIRECTORIES(src)

SET(SRC_LISTS
    src/keccakf.cpp
)

#add_definitions(-std=c++17)

ADD_LIBRARY(ckeccpp STATIC ${SRC_LISTS})

ADD_EXECUTABLE(test_keccakf1600 test/test_keccakf1600.cpp)
TARGET_LINK_LIBRARIES(test_keccakf1600 ckeccpp)

ADD_EXECUTABLE(test_keccakf800 test/test_keccakf800.cpp)
TARGET_LINK_LIBRARIES(test_keccakf800 ckeccpp)

ADD_EXECUTABLE(test_keccakf400 test/test_keccakf400.cpp)
TARGET_LINK_LIBRARIES(test_keccakf400 ckeccpp)

ADD_EXECUTABLE(test_keccakf200 test/test_keccakf200.cpp)
TARGET_LINK_LIBRARIES(test_keccakf200 ckeccpp)

