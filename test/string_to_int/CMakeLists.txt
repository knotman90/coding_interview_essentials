cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_string_to_int test_string_to_int.cpp)
target_link_libraries(test_string_to_int ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(test_string_to_int PUBLIC ${GTEST_INCLUDE_DIRS})

