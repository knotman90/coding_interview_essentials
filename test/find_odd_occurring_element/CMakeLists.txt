cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_find_odd_occurring_element test_find_odd_occurring_element.cpp)
target_link_libraries(test_find_odd_occurring_element ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_find_odd_occurring_element PUBLIC ${GTEST_INCLUDE_DIRS})

