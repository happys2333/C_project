//main function for the NORMAL version
//date : 2020-10-11
// written by : happys2333
#ifndef NORMAL_MAIN_H
#define NORMAL_MAIN_H
#include<fstream>
#include<string>
#include<iostream>
#include <ctime>
#include "CodeError.h"
void completed(int n,int dim,double **vectors){
    ofstream out("result.txt");
    clock_t start, finish;
    int k=n/2;
    double result = 0;
    start=clock();
    for(int j=0;j<k;j++){
        for(int i=dim-1;i>0;i--){
            if(i>=8){
                result += (
                        vectors[2*j][i]*vectors[2*j+1][i]+
                        vectors[2*j][i-1]*vectors[2*j+1][i-1]+
                        vectors[2*j][i-2]*vectors[2*j+1][i-2]+
                        vectors[2*j][i-3]*vectors[2*j+1][i-3]+vectors[2*j][i-4]*vectors[2*j+1][i-4]+
                        vectors[2*j][i-5]*vectors[2*j+1][i-5]+vectors[2*j][i-6]*vectors[2*j+1][i-6]+
                        vectors[2*j][i-7]*vectors[2*j+1][i-7]+vectors[2*j][i-8]*vectors[2*j+1][i-8]
                );
                i -= 8;
                continue;
            }
            result += (vectors[2*j][i]*vectors[2*j+1][i]);
        }
        out<<result<<endl;
    }
    finish = clock();
   printf("执行完成，用时： %f s",(double) (finish-start)/CLOCKS_PER_SEC );
}
void commandmode(){
    printf("欢迎使用命令行模式，请按照规定使用本程序：");
    int n=0;
    int dim=0;
    printf("请输入您的向量维度:");
    scanf("%d",&dim);
    printf("请输入您的向量个数:");
    scanf("%d",&n);
    if(n%2!=0){
        Wronglinenum(n);
        return;
    }
    double **vectors= new double *[n];
    for(int j=0;j<n;j++){
        vectors[j]=new double [dim];
    }
    double temp=0;
    printf("请依次输入您的向量:");
    for(int i=0;i<n;i++){
        for(int j=0;j<dim;j++){
            scanf("%lf",&temp);
            vectors[i][j]=temp;
        }
    }
    completed(n,dim,vectors);
}
void fileMode(){
    printf("欢迎使用文件模式\n"
           "请确保您的文件中的内容按照以结尾回车的方法分离每个数据\n");
    int n=0;
    int dim=0;
    printf("请输入您的向量维度:");
    scanf("%d",&dim);
    printf("请输入您的向量个数:");
    scanf("%d",&n);
    if(n%2!=0){
        Wronglinenum(n);
        return;
    }
    printf("请输入您的文件路径（绝对路径）\n");
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
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<dim;j++){
            in.getline(line,1024);
            vectors[i][j]=stod(line);
        }
    }
    completed(n,dim,vectors);
}




#endif //NORMAL_MAIN_H
