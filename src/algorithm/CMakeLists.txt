include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(algo_lib
    STATIC
        ${ALGO_SRCS}
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
    set(ALGO_SRC ${ALGO_DIR}/src/${SRC_FILE})
    message(STATUS "CPP_FILE: ${CPP_FILE}")
    message(STATUS "ALGO_SRC: ${ALGO_SRC}")

    add_executable(${EXE_FILE_NAME}
        ${ALGO_SRC}
        ${CMAKE_CURRENT_SOURCE_DIR}/test/${CPP_FILE}
    )
    target_link_libraries(${EXE_FILE_NAME}
        PRIVATE
        ${GTEST_BOTH_LIBRARIES}
    )
    install(TARGETS ${EXE_FILE_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/install/bin/algorithm)
endforeach()

install(TARGETS algo_lib DESTINATION ${CMAKE_INSTALL_PREFIX}/install/lib/algorithm)