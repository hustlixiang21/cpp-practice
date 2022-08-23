cmake_minimum_required(VERSION 3.21)
project(stack_calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack_calculator main.cpp Stack.h Calculator.h Calculator.cpp)
