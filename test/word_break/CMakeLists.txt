cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_word_break test_word_break.cpp)
target_link_libraries(test_word_break ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_word_break PUBLIC ${GTEST_INCLUDE_DIRS})

