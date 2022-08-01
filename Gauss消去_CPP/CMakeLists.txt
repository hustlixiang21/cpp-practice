cmake_minimum_required(VERSION 3.21)
project(Guass_CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(Guass_CPP main.cpp Matrix.cpp Matrix.h LinearEqu.cpp LinearEqu.h)
