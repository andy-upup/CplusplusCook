if(${WITH_CPP_SUGER})
  add_subdirectory(cplusplus_suger)
endif()

if(${WITH_ALGO})
  add_subdirectory(algorithm)
endif()

if(${WITH_DESIGN_PATTERN})
  add_subdirectory(design_pattern)
endif()

if(${WITH_EFFECTIVE})
  add_subdirectory(effective)
endif()

if(${WITH_CONCURRENCY})
  add_subdirectory(concurrency)
endif()

if(${WITH_OTHERS})
  add_subdirectory(others)
endif()
