cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_sorted_array_intersection test_sorted_array_intersection.cpp)
target_link_libraries(test_sorted_array_intersection ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_sorted_array_intersection PUBLIC ${GTEST_INCLUDE_DIRS})

