cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_merge_k_sorted_lists test_merge_k_sorted_lists.cpp)
target_link_libraries(test_merge_k_sorted_lists ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_merge_k_sorted_lists PUBLIC ${GTEST_INCLUDE_DIRS})

