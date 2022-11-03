cmake_minimum_required(VERSION 2.6)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
include_directories(../src)
include_directories(../include)


#add_library(json ../src/json.cc)
#add_library(parse ../src/parse.cc)
aux_source_directory(../src DIR_SRCS)



add_executable(Test test.cc ${DIR_SRCS})



