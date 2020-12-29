cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_min_stack test_min_stack.cpp)
target_link_libraries(test_min_stack ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_min_stack PUBLIC ${GTEST_INCLUDE_DIRS})

