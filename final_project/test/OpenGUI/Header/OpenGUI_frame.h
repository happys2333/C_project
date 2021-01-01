//
// Created by 开心 on 2020/12/24.
//

#ifndef OPENUI_OPENGUI_FRAME_H
#define OPENUI_OPENGUI_FRAME_H
#include "GUIroot.h"
#include <string>
#include <glew.h>
#include <glfw3.h>
#include <iostream>
class CFrame : UIkit {
private:
    bool Big = false;
    GLFWwindow *window;
    void initial(){

    }



    public:
    ~CFrame();
    CFrame(unsigned weight=200,unsigned height=200,unsigned int x=0,unsigned int y=0,std::string title="OpenGUI_frame");
    void add();
    void visualize();
    void BigScreen();
    void SmallScreen();

};

#endif //OPENUI_OPENGUI_FRAME_H
