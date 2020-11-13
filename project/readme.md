# CS205 C/C++ Programming Mid Project
## 概况
![license](https://img.shields.io/badge/license-MIT-yellowgreen)
![language](https://img.shields.io/badge/language-C%2B%2B-brightgreen)
![author](https://img.shields.io/badge/author-happys-blue)
![support](https://img.shields.io/badge/supported%20OS-Windows%20Linux%20macOS-red)
##### 测试平台：`windows10 x64` `macOS 10.15` `linux(Ubuntu)`
##### 编码：`UTF-8`
##### C++标准：`C++14`
## 目录
- [设计思路与分析](#设计思路与分析)
- [代码](#代码)
- [测试结果](#测试结果)
- [使用方法](#使用方法)
- [亮点与思考](#程序亮点与思考)
## 设计思路与分析
本次作业限制了数据的类型，只能使用float类型，考虑到各种平台的问题，我们首先考虑的是跨平台性，同时由于是以库的形式呈现，所以我们在不同平台下均使用C++14标准对程序进行编译       
##### 测试平台
操作系统：windows10 x64
CPU： Intel Core i5 9400
内存：16G
#### 基本框架
我们首先实现了一个矩阵，对矩阵进行了简单初始化，为了方便用户使用这个程序，我们对程序的运算符进行了重载，作为一个方便使用的库进行设计。
`本程序是一个矩阵运算的库，并非可以执行的文件，你需要将其调用到你自己的代码中`
#### 基本代码运行函数
本库包括了一个完整的矩阵类，你可以通过这个矩阵类实现你想实现的绝大部分矩阵方面的功能，由于库是为了实现通用性，我们摒弃了个别不能跨平台的方法，最终设计出了这套矩阵运行库。
####
对于矩阵乘法我们的优化主要是从以下方面进行优化         
- 优化硬件处理（有关访存方面）
- 展开运算（主要是for循环）
- 并行计算（采取了openmp的并行库）
- 针对硬件平台进行优化（使用Intel的SIMD）
- 针对CPU缓存相关处理（处理个别超过cache的矩阵）       
本程序默认打开O(3)编译模式，所以效率首先会提升一部分



## 代码

## 使用方法
本次代码采取了封装为库的思路，通过将代码进行库封装，可以非常简单的进行代码迁移，本程序的test文件中示范了一个简单的方法将程序加入到您的工程之中，并不会影响您的其他代码。
您的可以采用两种方法来使用本程序：
- 通过本地的cmake编译器对源代码进行编译（强烈推荐）
- 通过已经打包好的三种库进行运行（不能保证其他平台的运行正常）
本地编译请将您的控制台（终端）程序定位到本程序的source文件下通过以下指令编译我们生成的库
```shell
cmake CMakeLists.txt
make
```
`我们这里需要强调的是，由于macOS下自带的clang编译器并不支持我们使用的openmp，所以这里给出了一个教程帮助您在您的Mac上构建您的程序`
- 将您的控制台移动到source的文件下
- 安装gcc
```shell
brew install gcc
```
- 使用如下命令编译我们的库
```shell
gcc-10  -c -fopenmp -mfma library.cpp -o libmatrix.o
ar rcs libmatrix.a *.o
```
这样您就可以在您的Mac上使用这个库了

## 测试结果
对于五种不同的优化方法，我们获得了很多的

## 程序亮点与思考
