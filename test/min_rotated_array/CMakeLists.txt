cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_min_rotated_array test_min_rotated_array.cpp)
target_link_libraries(test_min_rotated_array ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_min_rotated_array PUBLIC ${GTEST_INCLUDE_DIRS})

