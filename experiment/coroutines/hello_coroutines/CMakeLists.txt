


#add_executable(hello_coroutines hello_coroutines)


add_executable(hello_cppcoro hello_cppcoro.cpp)
target_link_libraries(hello_cppcoro cppcoro )

add_executable(cpp_coro_cancellation cpp_coro_cancellation.cpp)
target_link_libraries(cpp_coro_cancellation cppcoro )
