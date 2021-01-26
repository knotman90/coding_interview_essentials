cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_max_gap test_max_gap.cpp)
target_link_libraries(test_max_gap ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_max_gap PUBLIC ${GTEST_INCLUDE_DIRS})

