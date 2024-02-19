if(${WITH_ALGO})
    set(ALGO_DIR ${CMAKE_SOURCE_DIR}/src/algorithm)

    aux_source_directory(${ALGO_DIR}/src ALGO_SRCS)
endif()

message(STATUS "ALGO_DIR: ${ALGO_DIR}")