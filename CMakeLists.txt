cmake_minimum_required(VERSION 3.20)
project(cpp_cook)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O0")
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -fno-elide-constructors")
add_definitions(-O0)

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

if(${WITH_OTHERS})
  include(${CMAKE_SOURCE_DIR}/cmake/Others.cmake)
endif()

include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(src)

if(BUILD_TEST)
  add_subdirectory(test)
endif()
