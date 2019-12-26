cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_stairs_climbing test_stairs_climbing.cpp)
target_link_libraries(test_stairs_climbing pthread ${GTEST_BOTH_LIBRARIES})
target_include_directories(test_stairs_climbing PUBLIC ${GTEST_INCLUDE_DIRS})

