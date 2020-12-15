cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


add_executable(test_min_difficulty_job_scheduler test_min_difficulty_job_scheduler.cpp)
target_link_libraries(test_min_difficulty_job_scheduler ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT}) 
target_include_directories(test_min_difficulty_job_scheduler PUBLIC ${GTEST_INCLUDE_DIRS})

