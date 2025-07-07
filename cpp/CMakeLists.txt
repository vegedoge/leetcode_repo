# minimum version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# define project
project(Lc_Debug VERSION 1.0 LANGUAGES CXX)

# include
# target_include_directories(test_main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_main test_main.cpp)
                
target_compile_options(test_main PUBLIC -Wall -Wextra -g)