add_subdirectory(src)

add_executable(cpp_suger ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

install(TARGETS cpp_suger
        DESTINATION ${CMAKE_INSTALL_PREFIX}/install/bin/cplusplus_suger)
