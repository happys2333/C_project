cmake_minimum_required(VERSION 3.17)
project(cuda CUDA)

set(CMAKE_CUDA_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
add_executable(cuda main.cu GPU.h CodeError.h LinkedList.h ArrayList.h)

set_target_properties(
        cuda
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)