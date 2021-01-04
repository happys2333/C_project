//
// Created by 开心 on 2020/12/24.
//

#include "../Header/OpenGUI_Button.hpp"




void CButton::setBackgroundColor(float red, float green, float blue, float alpha) {
    this->Background_red = red;
    this->Background_green = green;
    this->Background_blue = blue;
    this->Background_alpha = alpha;
}

CButton::CButton(std::string title, unsigned int width, unsigned int height, unsigned int x, unsigned int y) {
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->title = title;
}

bool CButton::isClick(int MouseX,int MouseY) {
    if(MouseX>=x&&MouseX<=x+width){
        if(MouseY<=y&&MouseY>=y-height){
            return true;
        }
    }
    return false;
}
using namespace std;
void CButton::draw(GLFWwindow * window,int WINwidth, int WINheight) {
    float pirx = (float)2/(float)WINwidth , piry = (float)2/(float)WINheight ;
    float Px = (-1+(float)x*pirx);
    float Py = (1-(float)y*piry);
    float addx=(float)width*pirx,addy=(float)height*piry;
    glBegin(GL_QUADS);
    glColor3f(Background_red, Background_green, Background_blue);
    glVertex3f(Px,Py,0.0);
    glColor3f(Background_red, Background_green, Background_blue);
    glVertex3f(Px+addx,Py,0.0);
    glColor3f(Background_red, Background_green, Background_blue);
    glVertex3f(Px+addx,Py+addy,0.0);
    glColor3f(Background_red, Background_green, Background_blue);
    glVertex3f(Px,Py+addy,0.0);
    glEnd();

}

CButton::~CButton() {
    fun = nullptr;
}

