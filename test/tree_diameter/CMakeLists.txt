cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_tree_diameter test_tree_diameter.cpp)
target_link_libraries(test_tree_diameter ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_tree_diameter PUBLIC ${GTEST_INCLUDE_DIRS})

