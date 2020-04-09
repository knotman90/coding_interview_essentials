cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_backspace_string_compare test_backspace_string_compare.cpp)
target_link_libraries(test_backspace_string_compare ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_backspace_string_compare PUBLIC ${GTEST_INCLUDE_DIRS})

