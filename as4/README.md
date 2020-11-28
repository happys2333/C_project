# CS205 C/C++ Programming Assignment 4
## 概况
![license](https://img.shields.io/badge/license-MIT-yellowgreen)![language](https://img.shields.io/badge/language-C%2B%2B-brightgreen)![author](https://img.shields.io/badge/author-happys-blue)![support](https://img.shields.io/badge/Supported%20platform-Windows%20macOS%20Linux-red)
##### 测试平台：`Linux macOS Windows`
#### 上次作业中，我们实现了对矩阵乘法的优化与实现，我们也对一部分的运算符进行了重载，但是我们认为应该本着*用户至上*的思想进一步让我们的代码进行完备，所以我们制作了本版
#### 目录
- [bug修正](#相关修正)
-     [新增功能](#新功能)
-     [新增代码](#新代码)
-     [运行效果](#运行效果)
## 相关修正
在上一版的程序中，我们发现在macOS中存在编译失败的问题，这是因为macOS中系统会默认使用Clang编译器而不使用Gcc编译器，所以我们对cmake中添加了一部分代码进行阻止在macOS下进行编译
```cmake
IF (WIN32)
	MESSAGE(STATUS "Your are using Windows")
ELSEIF (APPLE)
	MESSAGE(STATUS "Your are using MacOS ,this cmake can't be used in MacOS because clang will stop this project for using gcc")
    message(FATAL_ERROR "Error: We don't suppose the MacOS, please use the terminal to compile this program")
ELSEIF (UNIX)
	MESSAGE(STATUS "Your are using Linux")
ENDIF ()
```

## 新功能
## 新代码
## 运行效果
本版程序并没有对速度进行优化，所以我们测试数据均以方便展示为主，采取一个简单的10x10矩阵进行测试,其中实现均用随机矩阵。
