cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_smallest_range test_smallest_range.cpp)
target_link_libraries(test_smallest_range ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_smallest_range PUBLIC ${GTEST_INCLUDE_DIRS})

