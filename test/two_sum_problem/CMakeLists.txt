cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_two_numbers_sum test_two_numbers_sum.cpp)
target_link_libraries(test_two_numbers_sum ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_two_numbers_sum PUBLIC ${GTEST_INCLUDE_DIRS})

add_subdirectory(four_sum_problem)