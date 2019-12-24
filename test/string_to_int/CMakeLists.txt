cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_string_to_int test_string_to_int.cpp)
target_link_libraries(test_string_to_int pthread ${GTEST_BOTH_LIBRARIES})
target_include_directories(test_string_to_int PUBLIC ${GTEST_INCLUDE_DIRS})

