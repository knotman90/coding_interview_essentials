cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_median_sorted_arrays test_median_sorted_arrays.cpp)
target_link_libraries(test_median_sorted_arrays ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_median_sorted_arrays PUBLIC ${GTEST_INCLUDE_DIRS})

