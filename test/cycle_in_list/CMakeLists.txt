cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_cycle_in_list test_cycle_in_list.cpp)
target_link_libraries(test_cycle_in_list ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_cycle_in_list PUBLIC ${GTEST_INCLUDE_DIRS})

