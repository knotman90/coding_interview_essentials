cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_remove_duplicated_sorted_array_inplace test_remove_duplicated_sorted_array_inplace.cpp)
target_link_libraries(test_remove_duplicated_sorted_array_inplace ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_remove_duplicated_sorted_array_inplace PUBLIC ${GTEST_INCLUDE_DIRS})

