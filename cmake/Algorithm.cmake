if(${WITH_ALGO})
    set(SORT_DIR ${CMAKE_SOURCE_DIR}/src/algorithm/src/sort)

    aux_source_directory(${SORT_DIR}/src SORT_SRCS)
endif()

message(STATUS, "CPP20_DIR: ${CPP20_DIR}")