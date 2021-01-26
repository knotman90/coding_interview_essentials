cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_sudoku test_sudoku.cpp)
target_link_libraries(test_sudoku ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_sudoku PUBLIC ${GTEST_INCLUDE_DIRS})

