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

    void setGpa(float gpa) {
        GPA::gpa = gpa;
    }

    int getCredits() const {
        return credits;
    }

    void setCredits(int credits) {
        GPA::credits = credits;
    }

    float getSorce() const {
        return sorce;
    }

    void setSorce(float sorce) {
        GPA::sorce = sorce;
    }


    GPA& operator=(float g){
        this->gpa = g;
        return *this;
    }


};

#endif /* source_hpp */
