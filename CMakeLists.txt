cmake_minimum_required (VERSION 2.8)

project (demo)

add_executable(${PROJECT_NAME} 
	    src/json.cc
        UnitTest/test.cc
)


target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )
