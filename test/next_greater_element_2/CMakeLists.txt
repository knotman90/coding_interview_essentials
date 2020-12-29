cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_next_greater_element_2 test_next_greater_element_2.cpp)
target_link_libraries(test_next_greater_element_2 ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_next_greater_element_2 PUBLIC ${GTEST_INCLUDE_DIRS})

