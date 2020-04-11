cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_verify_BST test_verify_BST.cpp)
target_link_libraries(test_verify_BST ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_verify_BST PUBLIC ${GTEST_INCLUDE_DIRS})

