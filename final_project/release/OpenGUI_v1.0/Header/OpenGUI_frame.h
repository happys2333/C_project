//
// Created by 开心 on 2020/12/24.
//

#ifndef OPENUI_OPENGUI_FRAME_H
#define OPENUI_OPENGUI_FRAME_H

#include "GUIroot.h"

#include "Func.h"
#include <iostream>
#include <string>
#include "OpenGUI_Button.h"
#include "OpenGUI_TextBox.h"
#include "OpenGUI_label.h"

extern bool OPENGUI_Init;
static int ExitButton = -10;
class CFrame : UIkit {
private:

    float Background_red = 0;
    float Background_green = 0;
    float Background_blue = 0;
    float Background_alpha = 1;
    LinkedLists<CButton> CButtonlist;
    LinkedLists<CTextBox> CTextBoxlist;
    LinkedLists<CLabel> CLabellist;
    bool Big = false;
    GLFWwindow *window;
    static void keyCallback(GLFWwindow *windows, int key, int scancode, int action, int mods) {
        if (key == ExitButton && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(windows, GLFW_TRUE);
        }
    }
    static void errorCallback(int error, const char *des) {
        fprintf(stderr, "error: %s\n", des);
    }
    void initial(){
        if(OPENGUI_Init){
            glfwSetErrorCallback(errorCallback);
            if (!glfwInit()) {
                exit(EXIT_FAILURE);
            }
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 使用core-profile这行代码很重要
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        }
    }
    void mainloop();
    bool isPress(int button);
    void addin();
    public:
    ~CFrame();

    void setExitButton(int button);
    void PressTodo(int button);
    CFrame(unsigned weight=800,unsigned height=600,unsigned int x=0,unsigned int y=0,std::string title="OpenGUI_frame");
    void addLable(const CLabel &l);
    void addButton(const CButton &b);
    void addTextBox(const CTextBox &t);
    void visualize();
    void BigScreen();
    void SmallScreen();
    void Setsize(unsigned int width,unsigned int height);
    void ReNewWindow();
    void setBackgroundColor(float red,float green,float blue,float alpha);
};

#endif //OPENUI_OPENGUI_FRAME_H
