cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_gas_station test_gas_station.cpp)
target_link_libraries(test_gas_station ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_gas_station PUBLIC ${GTEST_INCLUDE_DIRS})

