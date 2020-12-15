cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_max_num_chunks_sorted test_max_num_chunks_sorted.cpp)
target_link_libraries(test_max_num_chunks_sorted ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_max_num_chunks_sorted PUBLIC ${GTEST_INCLUDE_DIRS})

