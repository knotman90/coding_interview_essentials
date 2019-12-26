cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_square_root test_square_root.cpp)
target_link_libraries(test_square_root ${CMAKE_THREAD_LIBS_INIT} ${GTEST_BOTH_LIBRARIES})
target_include_directories(test_square_root PUBLIC ${GTEST_INCLUDE_DIRS})
