cmake_minimum_required(VERSION 3.18)
project(CoroutinesExperiments)

include_directories("/home/dspataro/git/llvm-project/libcxx-build/include/c++/v1/" "/home/dspataro/git/cppcoro/include/")
link_directories("/home/dspataro/git/cppcoro/build/linux_x64_clang12.0.0_debug/lib/" )
link_directories("/home/dspataro/git/llvm-project/libcxx-build/lib/" )

set(CMAKE_C_COMPILER "/home/dspataro/git/llvm-project/clang-build/bin/clang")
set(CMAKE_CXX_COMPILER "/home/dspataro/git/llvm-project/clang-build/bin/clang++")

set(EXTRA_WARNING_GNU "-march=native -Wextra -Wdisabled-optimization  -Wshadow -Wpointer-arith -Wcast-qual -Wunreachable-code ")
#set(ADDITIONAL_INCLUDES "-isystem /home/dspataro/git/llvm-project/libcxx-build/include/c++/v1/")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall ${EXTRA_WARNING_GNU} ${ADDITIONAL_INCLUDES} -fcoroutines-ts -std=c++17 -nostdinc++ -stdlib=libc++ -pthread")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


add_subdirectory(coroutines)