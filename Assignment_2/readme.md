# CS205 C/C++ Programming Assignment 2
## 概况
![license](https://img.shields.io/badge/license-MIT-yellowgreen)
![language](https://img.shields.io/badge/language-C%2B%2B-brightgreen)
![author](https://img.shields.io/badge/author-happys-blue)
![support](https://img.shields.io/badge/supported%20OS-Windows%20Linux%20macOS-red)
##### 测试平台：`windows10 x64` `macOS 10.15` `linux(kali)`
##### 编码：`UTF-8`
##### C++标准：`C++11`
## 目录
- [设计思路与分析](#设计思路与分析)
- [代码](#代码)
- [测试结果](#测试结果)
- [亮点](#程序亮点)
## 设计思路与分析
本程序由于需要高精度运算，鉴于上次作业的方法具有一定局限性，所以本次我采用的是高精度的另一种算法，基本原理是通过对字符串输入分析。     
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
运行效果在平台上如下：      
windows平台    
![windows](运行结果/Windows.png)    
Linux平台        
![linux](运行结果/Linux.png)    
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
为了方便计算，提前定义了很多常见的科学函数
```cpp
#define M_exp "2.71828182845904523536028747135"
#define M_sqrt_2 "1.41421356237309504880168872421"
#define M_pi "3.14159265358979323846264338328"
#define M_sqrt_pi "1.77245385090551602729816748334"
#define M_pi_2 "1.57079632679489661923132169164"
```
通过流的操作实现了对科学计数法的处理，将可以对20位小数以内对数据进行精准处理，大于20位的则会报错，对于科学计数法负值如（1e-1）这种情况，我们最多在前面出现4个0，如果超过这个范围程序将会报错。   
例如（1e-4=0.0001)这种是合理的。   
```cpp
string doubletostr(long double num,int len){
        ostringstream out;
        if (len>20){
            return "wrong";
        }
        out.precision(len+1);
        out<<num;
        return out.str();
    }
    string changetonormal(string a1){
        int point=a1.find('e');
        string temp;
        for(int i=point+1;i<a1.length();i++){
            if(a1[i]<='9'&&a1[i]>='0') temp+=a1[i];
        }
        stringstream ss(a1),s2(temp);
        int len;
        long double d;
        ss>>d;
        s2>>len;
        if (a1.find('-')!=-1){
            int len2=a1.find('.');
            if (len-len2>3){return "wrong";}
        }
        return doubletostr(d,len);
    }
```
###这里是四则运算的板块内容说明
#### 加法
采取对浮点数可以精准运算的方法，通过上一次作业，可以很简单的对浮点数类型的方法进行运算，例如我们需要相加两个看似比较困难的数据   
1.0+9.99此时我们可以先查找数据中的.的位置，然后采取补0措施，同时对前面也采取补0，这样我们又转化成了之前的问题，从而实现了整个浮点数运算的方法   
相关代码如下：
```cpp
string addzeros(string str,int begin,int end){
    for (int i=begin;i<end;i++){
        str+="0";
    }
    return str;
}
string add(string a1,string a2){
        int a1len=a1.length()-a1.find('.')-1,a2len=a2.length()-a2.find('.')-1;
        if (a1.find('.')==-1){
            a1+='.';
            for (int i=0;i<a2len;i++){
                a1+='0';
            }
        } else if (a2.find('.')==-1){
            a2+='.';
            for (int i=0;i<a1len;i++){
                a2+='0';
            }
        } else if (a1len==a2len) {}
        else{
            if (a1len>a2len){
                for (int i=0;i<a1len-a2len;i++){
                    a2+='0';
                }
            } else{
                for (int i=0;i<a2len-a1len;i++){
                    a1+='0';
                }
            }
        }
        string temp= a1;
        for(int i=0;i<a1.length();++i){
            a1[i]=temp[a1.length()-i-1];
        }
        temp=a2;
        for(int i=0;i<a2.length();++i){
            a2[i]=temp[a2.length()-i-1];
        }
        int maxlength= a1.length()>a2.length()?a1.length():a2.length();
        a1.length()>a2.length()?a2=addzeros(a2,a2.length(),maxlength):a1=addzeros(a1,a1.length(),maxlength);
        a1+="0";a2+="0";
        string result,tempstr;
        int add;
        for(int i=0;i<maxlength;i++){
            add=a1[i]+a2[i]-'0'-'0';
            if (add>=10){
                if (a1[i+1]=='.'){
                    a1[i+2]+=1;
                    add-=10;
                    tempstr=(char(add) + '0');
                    result.insert(0, tempstr);
                    result.insert(0,".");
                    i++;
                    continue;
                }
                a1[i+1]+=1;
                add-=10;
            }
            tempstr=(char(add) + '0');
            result.insert(0, tempstr);
        }
        if(result[0]=='0'){
            result.erase(0,1);
        }
        result=delremin(result);
        return result;
    }
```
这里需要说明的是，此段代码参考了我上次的整数加法的方法，对于浮点数我采取的是当检测到小数点的时候直接跳过而将需要进位的数据向前移位，从而保证运算的准确性。
#### 减法
减法的思想和加法相似，区别是需要在计算前对两个字符串全部进行比较，这里只需要考虑两个整数情况，对于存在负数的情况，会在语法树解析中进行处理    
首先需要对其大小比较
```cpp
 bool big(string str1,string str2){
         if(str1.find('.')>str2.find('.')){
             return true;
         }else if(str1.find('.')<str2.find('.')){
             return false;
         }else{
             int len1 = str1.length(),len2 = str2.length();
             int len=min(len1,len2);
             for(int i=0;i<len;i++){
                 if(str1<str2){
                     return false;
                 }
                 else if (str1>str2){
                     return true;
                 }
             }
             if (len1>len2) return true;
             else return false;
         }
     }
```
然后采取和加法相似的技巧进行运算
```cpp
string minusnum(string a1,string a2){
        bool positve;
        big(a1,a2)?positve=true:positve=false;
        int a1len=a1.length()-a1.find('.')-1,a2len=a2.length()-a2.find('.')-1;
        if (a1.find('.')==-1){
            a1+='.';
            for (int i=0;i<a2len;i++){
                a1+='0';
            }
        } else if (a2.find('.')==-1){
            a2+='.';
            for (int i=0;i<a1len;i++){
                a2+='0';
            }
        } else if (a1len==a2len) {}
        else{
            if (a1len>a2len){
                for (int i=0;i<a1len-a2len;i++){
                    a2+='0';
                }
            } else{
                for (int i=0;i<a2len-a1len;i++){
                    a1+='0';
                }
            }
        }
        if (!positve){
            string t=a1;
            a1=a2;
            a2=t;
        }
        string temp= a1;
        for(int i=0;i<a1.length();++i){
            a1[i]=temp[a1.length()-i-1];
        }
        temp=a2;
        for(int i=0;i<a2.length();++i){
            a2[i]=temp[a2.length()-i-1];
        }
        int maxlength= a1.length()>a2.length()?a1.length():a2.length();
        a1.length()>a2.length()?a2=addzeros(a2,a2.length(),maxlength):a1=addzeros(a1,a1.length(),maxlength);
        a1+="0";a2+="0";
        string result,tempstr;
        int add;
        for(int i=0;i<maxlength;i++){
            add=a1[i]-a2[i];
            if (add<0){
                if (a1[i+1]=='.'){
                    a1[i+2]-=1;
                    add+=10;
                    tempstr=(char(add) + '0');
                    result.insert(0, tempstr);
                    result.insert(0,".");
                    i++;
                    continue;
                }
                a1[i+1]-=1;
                add+=10;
            }
            if (a1[i+1]=='.'){
                tempstr=(char(add) + '0');
                result.insert(0, tempstr);
                result.insert(0,".");
                i++;
                continue;
            }
            tempstr=(char(add) + '0');
            result.insert(0, tempstr);
        }
        if(result[0]=='0'){
            result.erase(0,1);
        }
        result=delremin(result);
        if(positve) return result;
        result.insert(0,"-");
        return result;
    }
```
#### 乘法
乘法原理告诉我们，乘以多少就相当于加多少次，所以乘法这里我直接是进行了循环相加来处理。
所以这样的实现是不能进行浮点数乘浮点数，只能进行浮点数乘以整数的实现    
这里对两个数进行了判断，将会对负负得正等情况进行判断。
```cpp
string multiple(string s1,string s2){
        if(s2.find('.')!=-1) {//浮点数乘法进行非精准计算
            string temp;
            long double a1=stod(s1),a2=stod(s2);
            temp=doubletostr(a1*a2,10);
            temp=delremin(temp);
            return temp;
        }
        long long needed=abs(stoll(s2));
        bool positve= true;
        if (s1[0]=='-'){
            string tmp="";
            for (long long i=1;i<s1.length();i++){
                tmp+=s1[i];
            }
            s1=tmp;
            positve= false;
        }
        if (needed<0){
            positve=(!positve);
        }
        string result="0",temp="0";
        for (long long i=0;i<needed;i++){
            temp=add(s1,temp);
        }
        temp=delremin(temp);
        if (positve){
            return temp;
        }
        result+='-';
        for (long long i=0;i<temp.length();i++){
            result+=temp[i];
        }
        return result;
    }
```
#### 除法
######目前尚未支持对除法的高精度运算
```cpp
string divide(string s1,string s2){
        long double a1=stold(s1),a2=stold(s2);
        string result= doubletostr(a1/a2,10);
        return delremin(result);
    }
```
### 其他科学函数
对于常用的科学函数，本程序并未实现更进一步的高精度计算，因为本身一部分的科学函数进行高精度计算是没有意义的，所以本程序对于绝大部分的函数都采取了使用原生C++库和一点优化的方法，其中三角函数等内容通过pi进行了伪高精度运算。
这里我们实现了如下的函数   
**顺便这里需要说明一下的是，对于三角函数采用了查表法解决，降低运算量，提高准确度，表的内容从网上采取的现成查好的表**  
- sqrt[] 开根
- sin[] sin函数
- cos[] cos函数
- tan[] tan函数
- cot[] cot函数
- exp[] 自然指数
- pow[] 乘方
- fact[] 阶乘(只支持整数）
- abs[] 绝对值
- max[] 获取最大值
- min[] 获取最小值
- get[] 使用一个科学数值    
*本软件可以使用的科学数值使用方法如下，在get[]中输入如下内容即可调用*
- pi 圆周率
- sqrt_2 根号2
- e 自然对数底数
- sqrt_pi 根号下圆周率
- pi_2 圆周率一半
## 语法树分析
#### 对于单行计算，采取递归方法进行计算，利用对语法树的分析，从而对数据进行计算，优先计算括号内，然后再计算科学函数，然后是乘除法，最后进行加减计算，在计算时，会对负负得正的情况进行处理，从而简化计算。
这里实现的是一个对输入的详细分析   
_首先是对科学计数法进行处理_
```cpp
//处理科学计数法
//处理科学计数法
        int in=0;
        while (true){
            in=expression.find('e',in);
            if(in==-1) break;
            else{
                string num="",temp="";
                int left=0,right=expression.length();
                for(int i=in-1;i>=0;i--){
                    if((expression[i]>='0'&&expression[i]<='9')||expression[i]=='.'){
                        num = expression[i]+num;
                    }
                    else{
                        left=i+1;
                        break;
                    }
                }if(num==""){
                    in++;
                    continue;
                }
                num+="e";
                for(int i=in+1;i<expression.length();i++){
                    if((expression[i]>='0'&&expression[i]<='9')||expression[i]=='.'){
                        num += expression[i];
                    }
                    else{
                        right=i;
                        break;
                    }
                }
                expression=expression.replace(left,right-left,changetonormal(num));
            }
        }
```
接下来是对正负号处理，这里处理的是1+-2=1-2这种类似的情况
```cpp
//对正负号处理
        int index=0,index2=0;
        while (true){
            index=expression.find('+',index);
            index2=expression.find('-',index2);
            if(index==-1&&index2==-1) break;
            if(index!=-1){
                if(expression[index+1]!='+'&&expression[index+1]!='-') {index++; continue;}
                if(index==0){
                    if(expression[index+1]=='-') expression=expression.replace(0,2,"-");
                    else expression=expression.replace(0,2,"");
                }
                else{
                    if(expression[index+1]=='-') expression=expression.replace(index,2,"-");
                    else expression=expression.replace(index,2,"+");
                }
            }
            else if(index2!=-1){
                if(expression[index2+1]!='+'&&expression[index2+1]!='-') { index2++;continue;}
                if(index2==0){
                    if(expression[index2+1]=='-') expression=expression.replace(0,2,"");
                    else expression=expression.replace(0,2,"-");
                }
                else{
                    if(expression[index2+1]=='-') expression=expression.replace(index2,2,"+");
                    else expression=expression.replace(index2,2,"-");
                }
            }
        }
```
然后对剩余进行乘法除法处理
```cpp
while (true){
                string num1,num2,result;
                index=expression.find_first_of('*'),index2=expression.find_first_of('/');
                if(index==-1&&index2==-1) break;
                if(index==-1) index=expression.length();
                if(index2==-1) index2=expression.length();
                if(index<index2){
                    int po=0;
                    for(int i=index-1;i>=0;i--){
                        if(expression[i]>='0'&&expression[i]<='9'){
                            num1 =expression[i]+num1;
                            po=i;
                        } else break;
                    }for (int i=index+1;i<expression.length();i++){
                        if(expression[i]>='0'&&expression[i]<='9'||expression[i]=='-'){
                            num2 +=expression[i];
                        } else break;
                    }
                    if(num1.length()==0||num2.length()==0) error(9,__FILE_NAME__,__LINE__);
                    result=fun.multiple(num1,num2);
                    expression=expression.replace(po,num1.length()+num2.length()+1,result);
                }
                else{
                    int po=0;
                    for(int i=index2-1;i>=0;i--){
                        if(expression[i]>='0'&&expression[i]<='9'){
                            num1 =expression[i]+num1;
                            po=i;
                        } else break;
                    }
                    for (int i=index2+1;i<expression.length();i++){
                        if(expression[i]>='0'&&expression[i]<='9'){
                            num2 +=expression[i];
                        } else break;
                    }
                    if(num1.length()==0||num2.length()==0) error(9,__FILE_NAME__,__LINE__);
                    result=fun.divide(num1,num2);
                    expression=expression.replace(po,num1.length()+num2.length()+1,result);
                }
            }
```
最后对整个最终表达式进行一遍加减处理即可
```cpp
while (true) {
                string num1,num2,result;
                index=expression.find_first_of('+'),index2=expression.find_first_of('-');
                if(index<=0&&index2<=0) break;
                if(index==-1) index=expression.length();
                if(index2==-1) index2=expression.length();
                if(index<index2){
                    int po=0;
                    for(int i=index-1;i>=0;i--){
                        if(expression[i]>='0'&&expression[i]<='9'){
                            num1 =expression[i]+num1;
                            po=i;
                        } else break;
                    }for (int i=index+1;i<expression.length();i++){
                        if(expression[i]>='0'&&expression[i]<='9'){
                            num2 +=expression[i];
                        } else break;
                    }
                    if(num1.length()==0||num2.length()==0) error(9,__FILE_NAME__,__LINE__);
                    result=fun.add(num1,num2);
                    expression=expression.replace(po,num1.length()+num2.length()+1,result);
                }
                else{
                    int po=0;
                    for(int i=index2-1;i>=0;i--){
                        if(expression[i]>='0'&&expression[i]<='9'){
                            num1 =expression[i]+num1;
                            po=i;
                        } else break;
                    }
                    for (int i=index2+1;i<expression.length();i++){
                        if(expression[i]>='0'&&expression[i]<='9'){
                            num2 +=expression[i];
                        } else break;
                    }
                    if(num1.length()==0||num2.length()==0) error(9,__FILE_NAME__,__LINE__);
                    result=fun.minusnum(num1,num2);
                    expression=expression.replace(po,num1.length()+num2.length()+1,result);
                }
```
#### 对于多行计算，采取类的方法进行处理，在处理这部分的时候调用了我上半年写的一个函数库的一部分，实现了仿照java的动态数组。
这个库可以访问我上半年在CSDN的帖子，更多内容由于本次作业尚未涉及，所以这里我就没有把整个库的内容全部放出    
帖子地址：[C++中实现java的方法（二）](https://blog.csdn.net/u013441283/article/details/104188281)   
在每次记录的时候，会对其对value进行计算（相当于进行一次单行运算）然后将这个返回值传入该动态数组。     
最后进行最后一行的表达式计算，在运算前会进行遍历将所有未知数全部替换，然后进行一次单行运算
## 代码
*main.cpp文件*
```cpp

```
*arratlist.h*
```cpp

```
*mathsin.h*
```cpp

```
*main.h*
```cpp

```
##测试结果
```shell script
您的系统是：mac
欢迎使用科学计算器中文版 版本号：1.0本程序是一款高级智能的计算器，采用c++编写而成，通过控制台指令进行操控，如果您想获取帮助请输入-h，如果您想退出请输入-q
请输入您的指令>>>-c get[e]+2+sin[3]
正在计算您的表达式： get[e]+2+sin[3] 请稍后
您的表达式的结果是： 4.85969982845904523536028747135 
请输入您的指令>>>-c ((9+1)*2)*2
正在计算您的表达式： ((9+1)*2)*2 请稍后
您的表达式的结果是： 40 
请输入您的指令>>>-h
本程序由开心制作
版本：1.0
相关可以操控的指令如下：
-h 获取计算器帮助
-c 表达式 进行简单的单行计算，支持（）和常用函数表达式
-s 进入多行表达式模式，在进入后会给予提示，请在进入后进行输入
本程序提供了如下的科学函数，可以在命令行中直接输入函数get(科学常数)名使用
例如：1*get[e]=2.71828182845904523536028747135（自然对数的底数）注意，在本程序中，所有函数使用[数字]进行表达，如sin[2],exp[2]等
本程序提供了如下的函数:自然对数的底数（e）根号2（sqrt_2）π（pi）根号π(sqrt_pi)二分之一π（pi_2）
-q 退出本程序
请输入您的指令>>>-c get[e]
正在计算您的表达式： get[e] 请稍后
您的表达式的结果是： 2.71828182845904523536028747135 
请输入您的指令>>>-s
欢迎进入多行操作模式，请输入您想计算的表达式
每行的格式是:变量名=表达式
最后一行的内容必须是表达式，不能带等号
XYYY=sin[3]
YY=2
XYYY+YY
2.141418
请输入您的指令>>>-c sin[3]+2
正在计算您的表达式： sin[3]+2 请稍后
您的表达式的结果是： 2.141418 
```
#### 对于不同平台的运行
Windows：

Linux：

macOS：

#### 单行复杂计算

#### 多行计算

## 程序亮点
- 多种平台的跨平台：可以自动识别几乎主流的三大操作系统（window平台，Linux平台和macOS平台）。
- 支持中文的输出：由于windows平台的限制，C++是不能直接在windows上输出中文的，但是本程序通过跨平台编译的方法实现了对windows平台上中的支持。
- 高精度的运算：通过直接使用计算机的字符串来操作数据从而实现了
- 快速读取用户输入：不使用cin而改用getchar的方法实现了对用户读取的快速录入，理论上会比cin的直接读取要快一倍以上。
- 多种模式：支持多种计算器模式运行。
- 科学计数法：本程序支持输入科学计数法的表达方法（例如：1e10）。
- 清晰的注释：采取仿照EA公司的注释规范，增强代码可读性。
- 更多的科学计算：参考了其他计算器的设计方法，实现了很多科学常数的存储，方便进行运算。
- 库文件和主函数的分开：通过将库和主函数的分开，可以更好对代码进行以后对迁移