cmake_minimum_required(VERSION 3.17)
project(project)
set(CMAKE_CXX_STANDARD 14)

link_directories(lib)
add_executable(project main.cpp)

target_link_libraries(project libmatrix.a)