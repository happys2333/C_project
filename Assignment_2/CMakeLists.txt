cmake_minimum_required(VERSION 3.17)
project(C__)
set(CMAKE_EXE_LINKER_FLAGS -static)
set(CMAKE_CXX_STANDARD 14)

add_executable(C__ main.cpp main.h arraylist.h mathsin.h)