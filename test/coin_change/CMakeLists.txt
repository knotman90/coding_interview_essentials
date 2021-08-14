cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_coin_change test_coin_change.cpp)
target_link_libraries(test_coin_change ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_coin_change PUBLIC ${GTEST_INCLUDE_DIRS})

