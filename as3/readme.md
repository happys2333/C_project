# CS205 C/C++ Programming Assignment 3
![license](https://img.shields.io/badge/License-MIT-yellowgreen)
![author](https://img.shields.io/badge/Author-%E5%BC%80%E5%BF%83-blue)
![language](https://camo.githubusercontent.com/c481d34384777e6ec69107514b9e61d6109e474b/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f6c616e67756167652d432532422532422d627269676874677265656e)
![platform](https://img.shields.io/badge/supported%20OS-Windows%20Linux%20macOS-red)
![lib](https://img.shields.io/badge/Used%20Lib-julia%20CUDA-yellow)
# 重要
如果您在使用本程序的时候无法打开，请安装Julia环境   
本程序内嵌了Julia语言的部分功能，从而提高了运算效率。   
本程序采取了GPU并行计算的思路，由于采用的是英伟达的CUDA核心，所以如果没有GPU支持的情况下请使用基础版本
# 目录
- [设计思路与分析](#设计思路)
- [测试情况](#测试)
- [代码](#程序代码)
- [亮点](#程序亮点)
# 设计思路
由于本程序中设计较多的浮点数内容的乘法运算，通常情况下CPU的浮点能力是较弱的，而GPU就会强的很多，所以本程序的主要部分是围绕于GPU的运算。   
在制作时候考虑到用户可能并不会都在有CUDA核心上都计算机运行本程序，所以本程序进行了多个不同情况都开发。鉴于不同环境的不同，所以本程序分成了以下的版本，分别在不同的文件夹中存放相关的可执行以及源代码：   
- 普通版本：这是最基础的C++版本，不支持高精度的浮点数，只能在数据量不算特别高的情况下加速运算。   
- CUDA版本：本版本进行了针对英伟达核心的GPU运算，属于两个版本中运算速度最快的程序。   
- Julia版本：本版本相对较慢，但是实现了高精度的浮点数运算，这里理论上可以支持超过50位小数以上的计算。     
**本程序中的数据量除了指总量以外更关注的是维度，如果维度较高则认为数据量高，同时，本程序运行时认为求点积是相邻两个向量运算，例如向量1和向量2，向量3和向量4**  
*所有程序运行完的结果均输出在程序根目录下的result.txt文件中*    
### 概况
三个不同版本中，有一些共同的特点，这里进行说明：    
三个版本的输入格式基本相同，支持两种不同模式： 
- 命令行模式  
本模式下，你可以通过命令行录入数据，你需要先录入你的向量维度，然后是向量的个数，在录入完成后要求你录入向量的内容，这里录入的格式如下：      
例如向量（1，0）（2，5）两个    
那么你在录入的时候，请先录入维度2，个数2，然后依次输入里面的数字，通过回车分割开每个数据：      
即：      
1     
0      
2     
5
- 文件模式          
在本模式下，我们需要先和命令行模式下一样，输入维度和个数，然后我们只需要输入你需要读取文件的**绝对路径**即可            
文件内容请和命令行模式下输入的格式相同，**以换行来分割数据**

### 普通版本
这里是最简单的版本，只实现了跨平台和CPU上的运算。效率是三个版本中中等的，不能支持高精度大数运算。  
基础思路是利用二维数组实现，所以开了一个vectors的二维数组，然后利用二维数组进行传递参数。    
优化算法是将维度高于8以上的数据进行一次运算就可得出结果，这样可以降低一定程度的运算量。    
优化部分代码实现如下  
```cpp
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
```
通过循环即可计算出本程序的答案
### Julia版本
普通版本采用Julia做为主要的计算部分，这里还是通过上次的跨平台方法解决。   
C语言部分以跨平台实现为主要内容：    
```cpp
#ifndef AS3_CROSS_SYSTEM_H
#define AS3_CROSS_SYSTEM_H
/* 这部分函数负责对平台进行识别，如果发现是windows平台就会更改控制台为UTF-8编码，以此来实现中文支持
 * */
#include<string>
using namespace std;
#if defined(__APPLE__)
# include <TargetConditionals.h>
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
    #define __FILE_NAME__ __FILE__
    return "windows";
#elif defined LINUX
    #define __FILE_NAME__ __FILE__
    return "linux";
#else
    return "unknown";
#endif
}
void changetheconsle(){
    string sy=findout();
    if(sy=="windows"){
        system("chcp 65001");
        system("cls");
    }
    if (sy=="unknown"){
        printf("Error: unknown system! please connect with the author(happys2333@outlook.com)");
        exit(1);
    }
}
#endif //AS3_CROSS_SYSTEM_H
```

值得声明的是，本程序的跨平台是通过不同平台进行不同的动态链接库编译实现，所以你可以利用如下方法在gcc中实现：
例如 Julia 被安装到 $JULIA_DIR，则可以用 gcc 来编译上面的测试程序 test.c:
```shell
gcc -o test -fPIC -I$JULIA_DIR/include/julia -L$JULIA_DIR/lib -Wl,-rpath,$JULIA_DIR/lib test.c - ljulia
```
### CUDA版本
**由于英伟达的限制，本版本的程序只能支持window10 64位系统和Linux进行运行，且应该在运行或者编译前配置好cuda环境**
思路较为简单，采取类似普通版本的思路，通过文件读写，实现本次运行的数据读取.
在这里选择GPU加速核心数目的时候采用了尽可能自行控制的原则，以960个核心同时计算为一组。



# 测试
测试模版为如下：
```shell

```
本程序使用的两个不同测试样例文件下载：

# 程序代码
### 普通版本
**与CUDA版本源码类似，只是没有加入GPU加速模块**
```cpp
```
### Julia版本
```julia
```
```cpp
```
### CUDA版本
```cpp
```
# 程序亮点
- 优秀的内存管理机制，保证无用的数组及时清理
- 没有使用float类型，而是通过double以及Julia自带高精度方法进行运算，提高精确度，支持较长的小数运算如超过16位以上的小数
- 通过并行GPU运算成倍提高程序运行效率
- 在用户没有相应的GPU环境的时候，可以选择普通的CPU运行模块来运行
- 支持中文输出
- 更好的数据结构，让用户可以更高效的利用空间
- 源代码与主要代码的分离，便于代码的开发与维护
- 支持多种不同模式运行，多个程序让用户可以直接选择
- Julia版本支持高精度大数运算
- 直接输出文件，可以多种模式输入，增强程序的效率
