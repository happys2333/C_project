#ifndef CUDA_GPU_H
#define CUDA_GPU_H
#include<iostream>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
using namespace std;

void initializeGPU(){

}
void commandmode(){



}
void printGPUInfo(){
    cudaError_t cudaStatus;
    int num;
    cudaDeviceProp prop;
    cudaStatus = cudaGetDeviceCount(&num);
    printf("GPU numbers = %d\n",num);
    for(int i=0;i<num;i++){
        cudaGetDeviceProperties(&prop,i);
        printf("name of GPU:%s\n",prop.name);
        printf("maxThreadsPerBlock : %d\n",prop.maxThreadsPerBlock);
    }
}
#endif