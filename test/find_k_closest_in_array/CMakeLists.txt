cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_find_k_closest_in_array test_find_k_closest_in_array.cpp)
target_link_libraries(test_find_k_closest_in_array ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_find_k_closest_in_array PUBLIC ${GTEST_INCLUDE_DIRS})

