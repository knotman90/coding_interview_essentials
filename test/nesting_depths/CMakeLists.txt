cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_nesting_depths test_nesting_depths.cpp)
target_link_libraries(test_nesting_depths ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_nesting_depths PUBLIC ${GTEST_INCLUDE_DIRS})

