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
        if(initialGUI){
            initialGUI = false;
            glfwInit();
            std::cout<<glGetString(GL_VERSION);
            glewExperimental = GL_TRUE;
            if (glewInit() != GLEW_OK)
            {
                std::cout << "Failed to initialize GLEW" << std::endl;
                return;
            }



        }
    }



    public:
    CFrame();
    ~CFrame();
    CFrame(unsigned weight=200,unsigned height=200,unsigned int x=0,unsigned int y=0,std::string title="OpenGUI_frame");
    void add();
    void visualize();
    void BigScreen();
    void SmallScreen();

};

#endif //OPENUI_OPENGUI_FRAME_H
