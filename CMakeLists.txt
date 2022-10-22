cmake_minimum_required(VERSION 3.1.0)

project(Json)

message("current build type is ${CMAKE_BUILD_TYPE}")

include_directories(include)


aux_source_directory(src  DIR_SRCS)

set(TEST ${DIR_SRCS})

# Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++14 support has been enabled by default.")

#add_executable(${PROJECT_NAME} ${TEST})
#include_directories("src")

#add_subdirectory("src")

#add_subdirectory("include")

add_subdirectory("UnitTest")
