cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_decode_string test_decode_string.cpp)
target_link_libraries(test_decode_string ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_decode_string PUBLIC ${GTEST_INCLUDE_DIRS})

