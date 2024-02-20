cmake_minimum_required(VERSION 3.20)
project(cpp_cook)

if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "Type of compiler is gnucxx.")
    set(CMAKE_CXX_FLAGS "${CMAKE_FLAGS} -std=c++17 -Wall -Werror")
endif()

find_package(GTest REQUIRED)

if(${WITH_CPP_SUGER})
    include(${CMAKE_SOURCE_DIR}/cmake/Cpp.cmake)
endif()

if(${WITH_ALGO})
    include(${CMAKE_SOURCE_DIR}/cmake/Algorithm.cmake)
endif()

if(${WITH_DESIGN_PATTERN})
    include(${CMAKE_SOURCE_DIR}/cmake/DesignPattern.cmake)
endif()

if(${WITH_EFFECTIVE})
    include(${CMAKE_SOURCE_DIR}/cmake/Effective.cmake)
endif()

if(${WITH_CONCURRENCY})
    include(${CMAKE_SOURCE_DIR}/cmake/Concurrency.cmake)
endif()

include_directories(
    ${GTEST_INCLUDE_DIRS}
)

add_subdirectory(src)

if(BUILD_TEST)
    add_subdirectory(test)
endif()