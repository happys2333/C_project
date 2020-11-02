cmake_minimum_required(VERSION 3.17)
project(source)

set(CMAKE_CXX_STANDARD 14)

add_library(source library.cpp library.h matrix.h)