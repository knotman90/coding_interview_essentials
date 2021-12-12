cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_spiral_matrix test_spiral_matrix.cpp)
target_link_libraries(test_spiral_matrix ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_spiral_matrix PUBLIC ${GTEST_INCLUDE_DIRS})

