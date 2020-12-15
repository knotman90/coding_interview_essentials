cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_dice_rolls test_dice_rolls.cpp)
target_link_libraries(test_dice_rolls ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_dice_rolls PUBLIC ${GTEST_INCLUDE_DIRS})

