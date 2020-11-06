cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_trapping_water test_trapping_water.cpp)
target_link_libraries(test_trapping_water ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_trapping_water PUBLIC ${GTEST_INCLUDE_DIRS})

