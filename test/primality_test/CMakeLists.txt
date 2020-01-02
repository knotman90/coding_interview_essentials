cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_primality_test test_primality_test.cpp)
target_link_libraries(test_primality_test ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_primality_test PUBLIC ${GTEST_INCLUDE_DIRS})

