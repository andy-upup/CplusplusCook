cmake_minimum_required(VERSION 3.20)
project(cpp_cook)

if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "Type of compiler is gnucxx.")
    set(CMAKE_CXX_FLAGS "${CMAKE_FLAGS} -std=c++17 -Wall -Werror")
endif()
# enable_testing()
find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

if(BUILD_TEST)
    add_subdirectory(test)
endif()