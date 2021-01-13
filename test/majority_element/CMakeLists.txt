cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_majority_element test_majority_element.cpp)
target_link_libraries(test_majority_element ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_majority_element PUBLIC ${GTEST_INCLUDE_DIRS})

