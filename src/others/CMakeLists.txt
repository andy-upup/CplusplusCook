include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(others_lib
    STATIC
        ${OTHERS_SRCS}
)

file(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)
foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(
        CPP_FILE
        ${TEST_FILE}
        NAME
    )
    string(REGEX REPLACE ".cpp" "" EXE_FILE_NAME ${CPP_FILE})
    string(REGEX REPLACE "_test_case" "" SRC_FILE ${CPP_FILE})
    set(OTHERS_SRCS ${OTHERS_DIR}/src/${SRC_FILE})
    message(STATUS "CPP_FILE: ${CPP_FILE}")
    message(STATUS "OTHERS_SRCS: ${OTHERS_SRCS}")

    add_executable(${EXE_FILE_NAME}
        ${OTHERS_SRCS}
        ${CMAKE_CURRENT_SOURCE_DIR}/test/${CPP_FILE}
    )
    target_link_libraries(${EXE_FILE_NAME}
        PRIVATE
        ${GTEST_BOTH_LIBRARIES}
        pthread
    )
    install(TARGETS ${EXE_FILE_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/install/bin/others)
endforeach()

install(TARGETS others_lib DESTINATION ${CMAKE_INSTALL_PREFIX}/install/lib/others)