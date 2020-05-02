cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_palindrome_partitioning2 test_palindrome_partitioning2.cpp)
target_link_libraries(test_palindrome_partitioning2 ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_palindrome_partitioning2 PUBLIC ${GTEST_INCLUDE_DIRS})

