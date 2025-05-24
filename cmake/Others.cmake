if(${WITH_OTHERS})
  set(OTHERS_DIR ${CMAKE_SOURCE_DIR}/src/others)

  aux_source_directory(${OTHERS_DIR}/src OTHERS_SRCS)
endif()

message(STATUS "OTHERS_DIR: ${OTHERS_DIR}")
