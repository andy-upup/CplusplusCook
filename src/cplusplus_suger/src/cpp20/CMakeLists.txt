include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(cpp20_lib
    STATIC
        ${CPP14_SRCS}
)

add_executable(cpp20_test_case
    ${CPP14_SRCS}
    ${CMAKE_CURRENT_SOURCE_DIR}/test/test_case.cpp
)

target_link_libraries(cpp20_test_case
    PRIVATE
    ${GTEST_BOTH_LIBRARIES}
)

install(TARGETS cpp20_lib       DESTINATION ${CMAKE_INSTALL_PREFIX}/install/lib/cplusplus_suger)
install(TARGETS cpp20_test_case DESTINATION ${CMAKE_INSTALL_PREFIX}/install/bin/cplusplus_suger)