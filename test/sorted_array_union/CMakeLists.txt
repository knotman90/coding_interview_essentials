cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_sorted_array_union test_sorted_array_union.cpp)
target_link_libraries(test_sorted_array_union ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_sorted_array_union PUBLIC ${GTEST_INCLUDE_DIRS})

