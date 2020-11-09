cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_five_starts_seller test_five_starts_seller.cpp)
target_link_libraries(test_five_starts_seller ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_five_starts_seller PUBLIC ${GTEST_INCLUDE_DIRS})

