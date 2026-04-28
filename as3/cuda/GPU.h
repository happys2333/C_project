#ifndef CUDA_GPU_H
#define CUDA_GPU_H
#include<fstream>
#include<string>
#include<iostream>
#include <cuda_runtime.h>

#include <device_launch_parameters.h>

#include "CodeError.h"

#include <ctime>

using namespace std;
/*
 * output to a file
 * */

/*
 * CUDA core
 * */
void tofree(double** needtofree,int len){
    for (int i=0;i<len;i++){
        delete [] needtofree[i];
    }
    delete [] needtofree;
}
__global__ void dot(double *c, const double *a, const double *b,int k)
{
    int i = threadIdx.x+k*960;
    c[i] = a[i] * b[i];
}
cudaError_t dodot(double *c, const double *a, const double *b, unsigned int size)
{
    double *dev_a = 0;
    double *dev_b = 0;
    double *dev_c = 0;
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) goto Error;

    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc((void**)&dev_c, size * sizeof(double));
    if (cudaStatus != cudaSuccess) goto Error;

    cudaStatus = cudaMalloc((void**)&dev_a, size * sizeof(double));
    if (cudaStatus != cudaSuccess) goto Error;

    cudaStatus = cudaMalloc((void**)&dev_b, size * sizeof(double));
    if (cudaStatus != cudaSuccess) goto Error;

    // Copy input vectors from host memory to GPU buffers.
    cudaStatus = cudaMemcpy(dev_a, a, size * sizeof(double), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) goto Error;

    cudaStatus = cudaMemcpy(dev_b, b, size * sizeof(double), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) goto Error;

    {
        int num = size/960;
        int remin = size%960;

        for(int i = 0; i <num;i++){
            dot<<<1,960>>>(dev_c, dev_a, dev_b,i);
        }
        if (remin > 0) dot<<<1,remin>>>(dev_c, dev_a, dev_b,num);
    }
    cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess) goto Error;

    cudaStatus = cudaDeviceSynchronize();
    if (cudaStatus != cudaSuccess) goto Error;

    cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(double), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess) goto Error;

    Error:
    cudaFree(dev_c);
    cudaFree(dev_a);
    cudaFree(dev_b);
    return cudaStatus;
}

void completed(const int n,const int dim,double** vectors){
    ofstream out("result.txt");
    clock_t start,finish,all=0;
    double *b;
    double *a;
    int k=n/2;
    cudaError_t cudaStatus;
    double sum=0;
    double *c = new double [dim];
    for(int i=0;i<k;i++){
        a = vectors [2*i];
        b = vectors [2*i+1];
        start = clock();
        cudaStatus = dodot(c, a, b, dim);
        finish =clock();
        for(int j=0;j<dim;j++){
            sum += c[j];
        }
        out<<sum<<endl;
        all +=(finish-start);
        sum = 0;
    }
    cudaDeviceReset();
    out.close();
    delete[] c;

    cout<<"All done!"<<endl<<"we use about "<<((double) all/CLOCKS_PER_SEC-0.1)<<"seconds to finish"<<endl;
}
void commandmode(){
    printf("welcome to use command mode\n");
    int n=0;
    int dim=0;
    int scanf_result;
    printf("Please enter your vector dimension:");
    scanf_result = scanf("%d",&dim);
    if (scanf_result != 1) { fprintf(stderr, "Invalid input\n"); exit(1); }
    printf("Please enter your number of vectors:");
    scanf_result = scanf("%d",&n);
    if (scanf_result != 1) { fprintf(stderr, "Invalid input\n"); exit(1); }
    if(n%2!=0){
        Wronglinenum(n);
        return;
    }
    double **vectors= new double *[n];
    for(int j=0;j<n;j++){
        vectors[j]=new double [dim];
    }
    double temp=0;
    printf("Please enter your vectors:");
    for(int i=0;i<n;i++){
        for(int j=0;j<dim;j++){
            scanf("%lf",&temp);
            vectors[i][j]=temp;
        }
    }
        completed(n,dim,vectors);
    tofree(vectors,n);
}
void fileMode(){
    printf("welcome to use file mode\n"
           "Please makesure your file txt type is same as the command mode\n");
    int n=0;
    int dim=0;
    int scanf_result;
    printf("Please enter your vector dimension:");
    scanf_result = scanf("%d",&dim);
    if (scanf_result != 1) { fprintf(stderr, "Invalid input\n"); exit(1); }
    printf("Please enter your number of vectors:");
    scanf_result = scanf("%d",&n);
    if (scanf_result != 1) { fprintf(stderr, "Invalid input\n"); exit(1); }
    if(n%2!=0){
        Wronglinenum(n);
        return;
    }
    printf("Please enter your file path(use absolute path)\n");
    string filepath;
    cin>>filepath;
    ifstream in(filepath);
    char line[1024];
    auto **vectors= new double *[n];
    for(int j=0;j<n;j++){
        vectors[j]=new double [dim];
    }
    if(!in){
        failtoread();
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<dim;j++){
            in.getline(line,1024);
            vectors[i][j]=stod(line);
        }
    }
        completed(n,dim,vectors);
    tofree(vectors,n);
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
