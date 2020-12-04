cmake_minimum_required(VERSION 3.0)

project(Book)


set(EXTRA_WARNING_GNU "-march=native -Wextra -Wdisabled-optimization  -Wunsafe-loop-optimizations -funsafe-loop-optimizations -Wshadow -Wpointer-arith -Wcast-qual -Wunreachable-code ")

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache) # Less useful to do it for linking, see edit2
endif(CCACHE_FOUND)
#set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,cppcoreguidelines-*, -header-filter=.;)

set (CMAKE_CXX_STANDARD 20)
if ( CMAKE_COMPILER_IS_GNUCC  OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall ${EXTRA_WARNING_GNU}")
endif ( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif ( MSVC )

find_package(GTest REQUIRED)

#tests
ADD_SUBDIRECTORY(test)
