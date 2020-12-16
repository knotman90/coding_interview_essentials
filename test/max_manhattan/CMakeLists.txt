cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_max_manhattan test_max_manhattan.cpp)
target_link_libraries(test_max_manhattan ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_max_manhattan PUBLIC ${GTEST_INCLUDE_DIRS})

