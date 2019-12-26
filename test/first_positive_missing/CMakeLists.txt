cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_first_positive_missing test_first_positive_missing.cpp)
target_link_libraries(test_first_positive_missing pthread ${GTEST_BOTH_LIBRARIES})
target_include_directories(test_first_positive_missing PUBLIC ${GTEST_INCLUDE_DIRS})

