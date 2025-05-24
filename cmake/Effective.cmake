if(${WITH_EFFECTIVE})
  set(EFFECTIVE_DIR ${CMAKE_SOURCE_DIR}/src/effective)

  aux_source_directory(${EFFECTIVE_DIR}/src EFFECTIVE_SRCS)
endif()

message(STATUS "EFFECTIVE_DIR: ${EFFECTIVE_DIR}")
