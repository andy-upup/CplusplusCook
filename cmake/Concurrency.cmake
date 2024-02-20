if(${WITH_CONCURRENCY})
    set(CONCURRENCY_DIR ${CMAKE_SOURCE_DIR}/src/concurrency)

    aux_source_directory(${CONCURRENCY_DIR}/src CONCURRENCY_SRCS)
endif()

message(STATUS "CONCURRENCY_DIR: ${CONCURRENCY_DIR}")