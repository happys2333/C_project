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
对于矩阵乘法我们的优化主要是从以下方面进行优化         
- 优化硬件处理
- 展开运算
- 并行计算
- 针对硬件平台进行优化

## 代码

## 使用方法
本次代码采取了封装为库的思路，通过将代码进行库封装，可以非常简单的进行代码迁移，本程序的test文件中示范了一个简单的方法将程序加入到您的工程之中，并不会影响您的其他代码。
您的可以采用两种方法来使用本程序：
- 通过本地的cmake编译器对源代码进行编译（强烈推荐）
- 通过已经打包好的三种库进行运行（不能保证其他平台的运行正常）
本地编译请将您的控制台（终端）程序定位到本程序的source文件下通过以下指令编译我们生成的库
```shell
cmake

```

## 测试结果


## 程序亮点与思考
