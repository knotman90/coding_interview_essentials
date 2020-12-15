cmake_minimum_required(VERSION 2.8)

project(Book)

option(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ENABLE_CLANG_TIDY "Run clang tidy" OFF)
option(ENABLE_CPPCHECK "Enable cppcheck static analyzer" OFF)

if(ENABLE_CPPCHECK)
    find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
    if (CMAKE_CXX_CPPCHECK)
        list(
            APPEND CMAKE_CXX_CPPCHECK 
                "--enable=warning"
                "--inconclusive"
                "--force" 
                "--inline-suppr"
                "--suppressions-list=${CMAKE_SOURCE_DIR}/CppCheckSuppressions.txt"
        )
    endif()
endif(ENABLE_CPPCHECK)

if(ENABLE_CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY clang-tidy)
endif(ENABLE_CLANG_TIDY)




set(EXTRA_WARNING_GNU "-march=native -Wextra -Wdisabled-optimization  -funsafe-loop-optimizations -Wshadow -Wpointer-arith -Wcast-qual -Wunreachable-code ")

#set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,cppcoreguidelines-*, -header-filter=.;)

set (CMAKE_CXX_STANDARD 20)
if ( CMAKE_COMPILER_IS_GNUCC  OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall ${EXTRA_WARNING_GNU} -Wunsafe-loop-optimizations")
endif ( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall ${EXTRA_WARNING_GNU} -fsanitize=address -fno-omit-frame-pointer")
endif()

if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif ( MSVC )

find_package(GTest REQUIRED)

#tests
ADD_SUBDIRECTORY(test)
