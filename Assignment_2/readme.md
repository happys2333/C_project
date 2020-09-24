# CS205 C/C++ Programming Assignment 2
## 概况
##### 测试平台：windows10 x64 macOS 10.15 linux(kali)
##### 编码：UTF-8
##### C++标准：C++11
## 目录
- [设计思路与分析](#设计思路与分析)
- [代码](#代码)
- [测试结果](#测试结果)
- [亮点](#程序亮点)
## 设计思路与分析
本程序由于需要高精度运算，鉴于上次作业的方法具有一定局限性，所以本次我采用的是高精度的另一种算法，基本原理是通过对字符串输入分析，然后转换成int数组进行计算。  
本程序在设计的时候综合考虑了主流操作系统的不同，所以利用对操作系统的判断采取不同措施，从而实现了对不同系统进行不同的编译
```cpp
#if defined(__APPLE__)
# include <TargetConditionals.h>
#include <vector>
# if defined(TARGET_OS_MAC) && TARGET_OS_MAC
#   define MAC
# endif
#elif defined(__linux__) || defined(__linux)
#   define LINUX
#elif !defined(SAG_COM) && (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
# define WIN32
#endif
string findout()
{
#if defined MAC
    return "mac";
#elif defined WIN32
    return "windows";
#elif defined LINUX
    return "linux";
#else
    return "unknown";
#endif
}
```
通过在不同操作系统环境下的实验，我得出了在中文版系统中只有window原生命令行不支持UTF-8的命令行输出，在macOS和Linux下均可以正常输出中文字符，所以我在判断完成后对windows操作系统进行了编码格式的更改
```cpp
void changetheconsle(){
    string sy=findout();
    if(sy=="windows"){
        system("chcp 65001");
    }
    if (sy=="unknown"){
        error(-1,__FILE_NAME__,__LINE__);
    }
    printf("您的系统是：%s\n",sy.c_str());
    printf("欢迎使用科学计算器中文版 版本号：1.0");
}
```
考虑到用户输入可能不只很短的式子，所以有可能存在现行scanf读取不够迅速等问题，采取了快速读取的方法（getchar）经过实验证明，这种方法可以比cin读取快数倍    
由于需要对不同的数据处理，原始代码量过于长，以至于难以维护，所以本次程序我将主程序和函数库加以分开，主程序内容如下：
```cpp
#include "main.h"
int main() {
    changethecnsle();
    mainloop();
}
```
所以本程序的主要部分在main.h文件下  
值得声明的是，本程序为了增强可读性，采取了从EA公司的源码学习的代码规范，在每个文件顶头会写明本文件的用途以及日前等信息，在每个模块采取了模块前注释的方法   
首先是基本对用户使用对提示信息，用户可以使用-q命令退出程序，且可以-h来获取帮助
```shell script
您的系统是：mac
欢迎使用科学计算器中文版 版本号：1.0本程序是一款高级智能的计算器，采用c++编写而成，通过控制台指令进行操控，如果您想获取帮助请输入-h，如果您想退出请输入-q
请输入您的指令>>>-h
本程序由开心制作
版本：1.0
相关可以操控的指令如下：
-h 获取计算器帮助
-c 表达式 进行简单的单行计算，支持（）和常用函数表达式
-s 进入多行表达式模式，在进入后会给予提示，请在进入后进行输入
-q 退出本程序
请输入您的指令>>>-q
感谢您的使用
```
对于主要运行部分我通过loop实现，从而保证在非严重错误情况下不会退出程序，为了增强可读性，增加了计算器类来保证代码的可读性。   
```cpp
void mainloop(){
    string cmd="";
    printf("本程序是一款高级智能的计算器，采用c++编写而成，通过控制台指令进行操控，如果您想获取帮助请输入-h，如果您想退出请输入-q\n");
    while (cmd!="-q"){
        printf("请输入您的指令>>>");
        cmd=readlinecmd();
        if (cmd[0]!='-'){
            error(-3,__FILE_NAME__,__LINE__);
            continue;
        } else if (cmd=="-h") gethelp();
        else if (cmd[1]=='c') onlyline(cmd);
        else if (cmd[1]=='s') multiline();
    }
    printf("感谢您的使用");
}
```

## 程序亮点
- 多种平台的跨平台：可以自动识别几乎主流的三大操作系统（window平台，Linux平台和macOS平台）。
- 支持中文的输出：由于windows平台的限制，C++是不能直接在windows上输出中文的，但是本程序通过跨平台编译的方法实现了对windows平台上中的支持。
- 高精度的运算：通过直接使用计算机的字符串来操作数据从而实现了
- 快速读取用户输入：不使用cin而改用getchar的方法实现了对用户读取的快速录入，理论上会比cin的直接读取要快一倍以上。
- 多种模式：支持多种计算器模式运行。
- 科学计数法：本程序支持输入科学计数法的表达方法（例如：1e10）。
- 清晰的注释：采取仿照EA公司的注释规范，增强代码可读性。