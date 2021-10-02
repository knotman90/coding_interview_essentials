cmake_minimum_required(VERSION 3.0 FATAL_ERROR)


add_executable(test_merge_intervals_2 test_merge_intervals_2.cpp Interval.cpp)
target_link_libraries(test_merge_intervals_2 ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_merge_intervals_2 PUBLIC ${GTEST_INCLUDE_DIRS})


add_executable(test_merge_intervals_2_entire_list test_merge_intervals_entire_list_2.cpp Interval.cpp)
target_link_libraries(test_merge_intervals_2_entire_list ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_merge_intervals_2_entire_list PUBLIC ${GTEST_INCLUDE_DIRS})

add_executable(test_meeting_rooms1 test_meeting_rooms1.cpp Interval.cpp)
target_link_libraries(test_meeting_rooms1 ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_meeting_rooms1 PUBLIC ${GTEST_INCLUDE_DIRS})

