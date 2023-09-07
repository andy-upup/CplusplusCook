include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

aux_source_directory(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    SUGER_SRC
)

add_library(cpp_suger
    STATIC
        ${SUGER_SRC}
)

install(TARGETS cpp_suger DESTINATION ${CMAKE_INSTALL_PREFIX}/cplusplus_suger/lib)