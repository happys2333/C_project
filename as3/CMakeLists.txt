cmake_minimum_required(VERSION 3.17)
project(as3)
set(CMAKE_CXX_STANDARD 14)

add_executable(as3 normal/main.cpp normal/LinkedList.h normal/cross_system.h)