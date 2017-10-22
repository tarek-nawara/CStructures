file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testlist ${SRCS})

TARGET_LINK_LIBRARIES(testlist
    list
    libgtest
    libgmock
)

add_test(NAME testlist
COMMAND testlist)
