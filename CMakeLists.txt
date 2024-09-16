cmake_minimum_required(VERSION 3.27)
project(chp)

set(CMAKE_CXX_STANDARD 17)

add_executable(chp main.cpp
        lab1/gcd.cpp
        lab1/lcm.cpp
        lab1/lcm.h)
