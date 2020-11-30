//
// Created by 开心 on 2020/11/30.
//

#ifndef SUSTECH_HELPER_FILE_H
#define SUSTECH_HELPER_FILE_H

#include <string>
#import <Foundation/Foundation.h>

using namespace std;
class file {
private:
    NSArray *documentPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,  NSUserDomainMask,YES);
    string fileName;
    NSString *FileName;
public:
    file(string name){
        fileName = name;
        FileName=[ stringByAppendingPathComponent:fileName];

    }

};


#endif //SUSTECH_HELPER_FILE_H
