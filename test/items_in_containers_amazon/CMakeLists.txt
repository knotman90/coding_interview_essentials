cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_items_in_containers_amazon test_items_in_containers_amazon.cpp)
target_link_libraries(test_items_in_containers_amazon ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_items_in_containers_amazon PUBLIC ${GTEST_INCLUDE_DIRS})

