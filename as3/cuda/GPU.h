#ifndef CUDA_GPU_H
#define CUDA_GPU_H
#include<iostream>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include "LinkedList.h"
#include "ArrayList.h"
#include <ctime>

using namespace std;
/*
 * output to a file
 * */

/*
 * CUDA core
 * */
class Vector{
    public:
    double *array;
    void set(int length){
        double vector[length];
        array=vector;
    }
};
__global__ void multi(int i,double result[],double x1,double x2){
    int point=threadIdx.x+threadIdx.y+i*960;
    result[point]=x1*x2;
}
void commandmode(){
    long long n=0;
    int dim=0;
    printf("Please enter your vector dimension:");
    scanf("%lld",&dim);
    printf("Please enter your number of vectors");
    scanf("%lld",&n);
    Vector *vectors=new Vector[n]();
    double temp=0;
    for(int i=0;i<n;i++){
        vectors[i].set(dim);
        for(int j=0;j<dim;j++){
            scanf("%lf",&temp);
            vectors[i].array[j]=temp;
        }
    }



}
void fileMode(){
    printf("welcome to use file mode\n"
           "Please makesure your file mode is same as the command mode\n");


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