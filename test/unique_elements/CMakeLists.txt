cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_unique_elements test_unique_elements.cpp)
target_link_libraries(test_unique_elements pthread ${GTEST_BOTH_LIBRARIES})
target_include_directories(test_unique_elements PUBLIC ${GTEST_INCLUDE_DIRS})
