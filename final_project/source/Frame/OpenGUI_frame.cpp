

#include <unistd.h>
#include "../Header/OpenGUI_frame.hpp"

bool OPENGUI_Init = true;
int MouseX,MouseY;
void curse_poscallback(GLFWwindow *window, double x, double y)
{
    MouseX = x;
    MouseY = y;
}
void CFrame::visualize() {
    if (!glfwInit()){
        glfwTerminate();
        exit(1);
    }
    window = glfwCreateWindow(width,height,title.c_str(), nullptr,nullptr);

    if(window==nullptr){
        std::cout<<"Error: Failed to create an Window"<<std::endl;
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);
    glfwSetWindowPos(window,x,y);
    glfwSetCursorPosCallback(window, curse_poscallback);
    mainloop();
}

CFrame::CFrame(GLint weight, GLint height, GLint x, GLint y, std::string title) {
    this->width=weight;
    this->height=height;
    this->x = x;
    this->y = y;
    this->title = title;
    getPre();
}

void CFrame::BigScreen() {
    Big = true;
}

void CFrame::SmallScreen() {
    Big = false;
}

CFrame::~CFrame() {
    ExitButton = 0;
    Background_red = 0;
    Background_green = 0;
    Background_blue = 0;
    Background_alpha = 0;
    CButtonlist.free();
    CLabellist.free();

}

void CFrame::mainloop() { bool t= true;
    while (!glfwWindowShouldClose(window)){
        t=true;
        glClearColor(Background_red, Background_green, Background_blue, Background_alpha);
        glClear( GL_COLOR_BUFFER_BIT);
        if(ExitButton!=-10){
            if(isPress(ExitButton)){
                glfwSetWindowShouldClose(window,true);
            }
        }

        for(int i=0;i<CButtonlist.size();i++){
            DrawButton(CButtonlist.get(i));
            if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS){
                for(int j=0;j<CButtonlist.size();j++){
                    if(CButtonlist.get(j).isClick(MouseX,MouseY)&&t){
                        t = false;
                        CButtonlist.get(j).DoButtonFun();
                        break;
                    }
                }
            }
        }
        for(int i=0;i<CLabellist.size();i++){
            CLabellist.get(i).Draw(preX, preY);
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void CFrame::Setsize(GLint width, GLint height) {
    this->width = width;
    this->height = height;
    getPre();
}

void CFrame::ReNewWindow() {
    glViewport(x,y,width,height);
}
void CFrame::setExitButton(int button) {
    ExitButton = button;
}


void CFrame::addLable(const CLabel &l) {
    CLabellist.add(l);
}

void CFrame::addButton(const CButton &b) {
    CButtonlist.add(b);
}

bool CFrame::isPress(int button) {
    return glfwGetKey(window,button)==GLFW_PRESS;
}



void CFrame::setBackgroundColor(float red, float green, float blue, float alpha) {
    this->Background_red = red;
    this->Background_green = green;
    this->Background_blue = blue;
    this->Background_alpha = alpha;
}

GLFWwindow *CFrame::getWindow() const {
    return window;
}

void CFrame::DrawButton(CButton b) {
    GLint x = b.getX(),y = b.getY();
    float Px = (-1+(float)x*preX);
    float Py = (1-(float)y*preY);
    float r = b.getBackgroundRed(),bl = b.getBackgroundBlue(),g = b.getBackgroundGreen();
    float addx=(float)b.getWidth()*preX,addy=(float)b.getHeight()*preY;
    glBegin(GL_QUADS);
    glColor3f(r, bl, g);
    glVertex3f(Px,Py,0.0);
    glColor3f(r, bl, g);
    glVertex3f(Px+addx,Py,0.0);
    glColor3f(r, bl, g);
    glVertex3f(Px+addx,Py+addy,0.0);
    glColor3f(r, bl, g);
    glVertex3f(Px,Py+addy,0.0);
    glEnd();
}

void CFrame::getPre() {
    preX = (float)2/(float)width , preY = (float)2/(float)height ;
}









