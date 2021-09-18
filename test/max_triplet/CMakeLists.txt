cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_max_triplet test_max_triplet.cpp)
target_link_libraries(test_max_triplet ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_max_triplet PUBLIC ${GTEST_INCLUDE_DIRS})

