//
//  source.hpp
//  SUSTech_Helper
//
//  Created by 开心 on 2020/12/8.
//

#ifndef source_hpp
#define source_hpp

#include <stdio.h>
#include <vector>

using namespace std;
class score{
    
};
class GPA {
private:
    float gpa=0;
    int credits=0;
    float sorce =0;
public:
    GPA(float sorce,int classsorce){
        this->sorce = sorce;
        this->credits = classsorce;
        
    }
    ~GPA(){
        gpa = 0;
        credits = 0;
        sorce = 0;
    }
    float getGpa() const {
        return gpa;
    }

    int getCredits() const {
        return credits;
    }
    float getSorce() const {
        return sorce;
    }
    GPA& operator=(float g){
        this->gpa = g;
        return *this;
    }
    GPA& operator+(GPA& g){
        this->credits = this->credits+g.credits;
        this->gpa += g.gpa;
        
        
        return *this;
    }


};

#endif /* source_hpp */
