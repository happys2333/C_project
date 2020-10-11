/****
 * julia version for the dot vectors
 * speed : slow
 * difficulty to use : not easy
 * system :Windows Linux Mac OS with julia
 * author : happys
 * date : 2020-10-9
 * ****/
#include <julia.h>
#include <zconf.h>
#include <string>
#include "cross_system.h"
using namespace std;
JULIA_DEFINE_FAST_TLS()
string path;
void setpathofjulia(){
    path ="include(\"";
    char *buffer;
    if((buffer = getcwd(NULL, 0)) == NULL)
    {
        perror("getcwd error");
    }
    else
    {
        path+=buffer;
        free(buffer);
    }
    path= path.substr(0,path.find("as3/"));
    path += "as3/Julia/Juliacore.jl\")";
}
int main(int argc, char *argv[])
{
    changetheconsle();
    setpathofjulia();
    printf("欢迎使用向量点乘计算器，您正在使用的是Julia版本\n"
           "我们强烈推荐您使用本程序在您对数据处理要求精度较高或者您需要一个相对较快的速度的情况下\n"
           "本程序需要配置Julia环境，具体配置方法请参考readme中的内容\n");
    jl_init();
    printf("正在初始化Julia核心程序请稍后\n");
    jl_eval_string(path.c_str());
    jl_atexit_hook(0);
    return 0;
}
