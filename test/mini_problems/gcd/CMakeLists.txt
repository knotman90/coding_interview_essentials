cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_mini_problems_gcd test_mini_problems_gcd.cpp)
target_link_libraries(test_mini_problems_gcd ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_mini_problems_gcd PUBLIC ${GTEST_INCLUDE_DIRS})

