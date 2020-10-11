cmake_minimum_required(VERSION 3.17)
project(cuda CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(cuda main.cu GPU.h CodeError.h)

set_target_properties(
        cuda
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)