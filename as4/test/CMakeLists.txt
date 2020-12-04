cmake_minimum_required(VERSION 3.17)
project(project)
set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

link_directories(lib)

add_executable(project main.cpp)

target_link_libraries(project libmatrix.a)