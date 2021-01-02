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
class CFrame : UIkit {
private:
    int ExitButton = -10;
    int Background_red = 0;
    int Background_green = 0;
    int Background_blue = 0;
    int Background_alpha = 1;
    LinkedLists<CButton> CButtonlist;
    LinkedLists<CTextBox> CTextBoxlist;
    LinkedLists<CLabel> CLabellist;
    bool Big = false;
    GLFWwindow *window;
    static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
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
    void key_callback( GLFWwindow* window , int key,int scancode, int action, int mode );
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
    void setBackgroundColor(int red,int green,int blue,int alpha);
};

#endif //OPENUI_OPENGUI_FRAME_H
