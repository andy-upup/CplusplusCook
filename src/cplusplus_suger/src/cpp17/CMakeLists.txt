include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(cpp17_lib STATIC ${CPP17_SRCS})

add_executable(cpp17_test_case ${CPP17_SRCS}
                               ${CMAKE_CURRENT_SOURCE_DIR}/test/test_case.cpp)

target_link_libraries(cpp17_test_case PRIVATE ${GTEST_BOTH_LIBRARIES})

install(TARGETS cpp17_lib
        DESTINATION ${CMAKE_INSTALL_PREFIX}/install/lib/cplusplus_suger)
install(TARGETS cpp17_test_case
        DESTINATION ${CMAKE_INSTALL_PREFIX}/install/bin/cplusplus_suger)
