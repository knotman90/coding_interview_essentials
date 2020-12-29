cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_kth_largest_in_stream test_kth_largest_in_stream.cpp)
target_link_libraries(test_kth_largest_in_stream ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_kth_largest_in_stream PUBLIC ${GTEST_INCLUDE_DIRS})

