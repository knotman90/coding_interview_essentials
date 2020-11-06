cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_node_from_the_end test_node_from_the_end.cpp)
target_link_libraries(test_node_from_the_end ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_node_from_the_end PUBLIC ${GTEST_INCLUDE_DIRS})

