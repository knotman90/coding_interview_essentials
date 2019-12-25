cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_exponentiation test_exponentiation.cpp)
target_link_libraries(test_exponentiation pthread ${GTEST_BOTH_LIBRARIES})
target_include_directories(test_exponentiation PUBLIC ${GTEST_INCLUDE_DIRS})

