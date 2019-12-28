cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_wave_array test_wave_array.cpp)
target_link_libraries(test_wave_array pthread ${GTEST_BOTH_LIBRARIES})
target_include_directories(test_wave_array PUBLIC ${GTEST_INCLUDE_DIRS})

