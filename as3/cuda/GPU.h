#ifndef CUDA_GPU_H
#define CUDA_GPU_H
#include<iostream>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include "CodeError.h"
#include <ctime>
#include <fstream>

using namespace std;
/*
 * output to a file
 * */

/*
 * CUDA core
 * */
ofstream out("result.txt");
dim3 grid(1,1,1),block(96,10,1);
class Vector{
    public:
    double *array;
    void set(int length){
        double vector[length];
        array=vector;
    }
};
__global__ void multitwovector(int i,long double result[],Vector v1,Vector v2){
    int point=threadIdx.x*blockDim.y+threadIdx.y+i*960;
    result[point]=v1.array[point]*v2.array[point];
}
__global__ void addvector(int i,long double needto[],int dim,long double result[]){

}

void completed(long long n,int dim,Vector* vectors){
    long double result,cuda_result;
    long double added[dim],cuda_added[dim];
    long long neeedtodo=n/2;
    Vector *cuda_vector1,*cuda_vector2;
    int needtobemul=dim/960,reminmult=dim%960;
    int progress=200/n,nowprogress=0;
    cudaMalloc((void**)&cuda_result,sizeof(long double));
    cudaMalloc((void**)&cuda_vector2,sizeof(Vector));
    cudaMalloc((void**)&cuda_vector1,sizeof(Vector));
    cudaMalloc((void**)&cuda_added,sizeof(long double)*dim);
    dim3 grid2(1,1,1),block2(reminmult,1,1);
    for(int k=0;k<neeedtodo;k++){
        cudaMemcpy(cuda_vector1,&vectors[2*k],sizeof(Vector),cudaMemcpyHostToDevice);
        cudaMemcpy(cuda_vector2,&vectors[2*k+1],sizeof(Vector),cudaMemcpyHostToDevice);
        for(int i=0;i<needtobemul;i++){
            multitwovector<<<grid,block>>>(i,cuda_added,cuda_vector1,cuda_vector2);
        }
        multitwovector<<<grid2,block2>>>(needtobemul,cuda_added,cuda_vector1,cuda_vector2);



        nowprogress+=progress;
        out<<result<<endl;
        cout<<nowprogress<<"% has been done"<<endl;
    }
    printf("All work has been completed, and we use about %d ms to finish the job.\n",);
}
void commandmode(){
    long long n=0;
    int dim=0;
    printf("Please enter your vector dimension:");
    scanf("%d",&dim);
    printf("Please enter your number of vectors");
    scanf("%lld",&n);
    if(n%2!=0){
        Wronglinenum(n);
        return;
    }
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
    long long n=0;
    int dim=0;
    printf("Please enter your vector dimension:");
    scanf("%lld",&dim);
    printf("Please enter your number of vectors");
    scanf("%lld",&n);
    if(n%2!=0){
        Wronglinenum(n);
        return;
    }
    printf("Please enter your file path(use absolute path)");
    string filepath;
    cin>>filepath;
    ifstream in(filepath);
    string line;
    Vector *vectors=new Vector[n]();
    if(!in){
        failtoread();
    }
    for(int i=0;i<n;i++){
        vectors[i].set(dim);
        for(int j=0;j<dim;j++){
            getline (in, line);
            vectors[i].array[j]=stod(line);
        }
    }


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