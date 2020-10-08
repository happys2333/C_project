
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
