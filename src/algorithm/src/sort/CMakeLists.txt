include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(algo_sort_lib
    STATIC
        ${SORT_SRCS}
)

add_executable(sort_test_case
    ${SORT_SRCS}
    ${CMAKE_CURRENT_SOURCE_DIR}/test/test_case.cpp
)

target_link_libraries(sort_test_case
    PRIVATE
    ${GTEST_BOTH_LIBRARIES}
)

install(TARGETS algo_sort_lib  DESTINATION ${CMAKE_INSTALL_PREFIX}/install/lib/algorithm)
install(TARGETS sort_test_case DESTINATION ${CMAKE_INSTALL_PREFIX}/install/bin/algorithm)