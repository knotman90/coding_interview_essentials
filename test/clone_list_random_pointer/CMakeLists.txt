cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_clone_list_random_pointer test_clone_list_random_pointer.cpp)
target_link_libraries(test_clone_list_random_pointer ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_clone_list_random_pointer PUBLIC ${GTEST_INCLUDE_DIRS})

