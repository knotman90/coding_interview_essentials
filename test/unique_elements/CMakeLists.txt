cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_unique_elements test_unique_elements.cpp)
target_link_libraries(test_unique_elements ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(test_unique_elements PUBLIC ${GTEST_INCLUDE_DIRS})
