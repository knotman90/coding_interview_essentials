cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_delete_duplicates_list test_delete_duplicates_list.cpp)
target_link_libraries(test_delete_duplicates_list ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_delete_duplicates_list PUBLIC ${GTEST_INCLUDE_DIRS})


