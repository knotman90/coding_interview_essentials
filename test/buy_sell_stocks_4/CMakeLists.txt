cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_buy_sell_stocks_4 test_buy_sell_stocks_4.cpp)
target_link_libraries(test_buy_sell_stocks_4 ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_buy_sell_stocks_4 PUBLIC ${GTEST_INCLUDE_DIRS})

