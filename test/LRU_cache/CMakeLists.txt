cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_LRU_cache test_LRU_cache.cpp)
target_link_libraries(test_LRU_cache ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_LRU_cache PUBLIC ${GTEST_INCLUDE_DIRS})

