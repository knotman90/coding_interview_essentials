cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_mirror_binary_tree test_mirror_binary_tree.cpp)
target_link_libraries(test_mirror_binary_tree ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_mirror_binary_tree PUBLIC ${GTEST_INCLUDE_DIRS})

