cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_sort_colors test_sort_colors.cpp)
target_link_libraries(test_sort_colors ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_sort_colors PUBLIC ${GTEST_INCLUDE_DIRS})

