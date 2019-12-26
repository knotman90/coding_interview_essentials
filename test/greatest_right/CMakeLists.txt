cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_greatest_right test_greatest_right.cpp)
target_link_libraries(test_greatest_right ${CMAKE_THREAD_LIBS_INIT} ${GTEST_BOTH_LIBRARIES})
target_include_directories(test_greatest_right PUBLIC ${GTEST_INCLUDE_DIRS})
