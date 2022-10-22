


add_executable(${PROJECT_NAME} test.cpp ../${DIR_SRCS})

target_link_libraries(${PROJECT_NAME} gtest)