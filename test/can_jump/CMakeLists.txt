cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_can_jump test_can_jump.cpp)
target_link_libraries(test_can_jump ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_can_jump PUBLIC ${GTEST_INCLUDE_DIRS})

