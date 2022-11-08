cmake_minimum_required (VERSION 2.8)
set(CMAKE_C_COMPILER  "/usr/bin/clang")
set(CMAKE_CXX_COMPILER  "/usr/bin/clang++")

project (demo)

add_executable(${PROJECT_NAME} 
        src/json.cc
        src/parse.cc
        UnitTest/test.cc
        
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )
