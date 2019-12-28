cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_two_string_anagram test_two_string_anagram.cpp)
target_link_libraries(test_two_string_anagram ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(test_two_string_anagram PUBLIC ${GTEST_INCLUDE_DIRS})
