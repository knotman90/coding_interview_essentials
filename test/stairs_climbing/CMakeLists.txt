cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_stairs_climbing test_stairs_climbing.cpp)
target_link_libraries(test_stairs_climbing ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(test_stairs_climbing PUBLIC ${GTEST_INCLUDE_DIRS})

