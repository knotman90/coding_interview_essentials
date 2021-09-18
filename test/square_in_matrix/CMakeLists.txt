cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_square_in_matrix test_square_in_matrix.cpp)
target_link_libraries(test_square_in_matrix ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_square_in_matrix PUBLIC ${GTEST_INCLUDE_DIRS})

