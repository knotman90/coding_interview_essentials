cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_power_set test_power_set.cpp)
target_link_libraries(test_power_set ${CMAKE_THREAD_LIBS_INIT} ${GTEST_BOTH_LIBRARIES})
target_include_directories(test_power_set PUBLIC ${GTEST_INCLUDE_DIRS})
