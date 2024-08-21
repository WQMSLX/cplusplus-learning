cmake_minimum_required(VERSION 3.20)
project(
    engine
    LANGUAGES CXX C
    VERSION 0.1.0
)
add_executable(main src/main.cpp)
target_include_directories(main PRIVATE include)