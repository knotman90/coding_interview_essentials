cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_allocate_books test_allocate_books.cpp)
target_link_libraries(test_allocate_books ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_allocate_books PUBLIC ${GTEST_INCLUDE_DIRS})

