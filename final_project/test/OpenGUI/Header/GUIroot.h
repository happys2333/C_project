//
// Created by 开心 on 2020/12/31.
//

#ifndef OPENGUI_GUIROOT_H
#define OPENGUI_GUIROOT_H
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <string>
void InitGUI(){
    glfwInit();
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return;
    }
    std::cout<<glGetString(GL_VERSION);
    glewExperimental = GL_TRUE;
}
class UIkit{
protected:
    unsigned int x=0,y=0;
    unsigned int width=0,high=0;
    int id;
    std::string title;
public:
    int getX() const {
        return x;
    }

    void setX(int x) {
        UIkit::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        UIkit::y = y;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        UIkit::id = id;
    }

    const std::string &getTitle() const {
        return title;
    }
    void setTitle(const std::string &title) {
        UIkit::title = title;
    }

};
#endif //OPENGUI_GUIROOT_H
