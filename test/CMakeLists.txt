file(GLOB TEST_FILES ${CMAKE_SOURCE_DIR}/test/*.cpp)

message(STATUS "TEST_FILES: ${TEST_FILES}")
set(CMAKE_CXX_FLAGS "${CMAKE_FLAGS} -std=c++17 -Wall -Werror")

foreach(TEST_FILE ${TEST_FILES})
  get_filename_component(FULL_FILE_NAME ${TEST_FILE} NAME)
  string(REGEX REPLACE ".cpp" "" FILE_NAME ${FULL_FILE_NAME})
  message(STATUS "FILE_NAME: ${FILE_NAME}")

  add_executable(${FILE_NAME} ${CMAKE_SOURCE_DIR}/test/${FULL_FILE_NAME})
  target_link_libraries(${FILE_NAME} PRIVATE ${GTEST_BOTH_LIBRARIES} pthread)
  install(TARGETS ${FILE_NAME}
          RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/test/bin)
endforeach()
