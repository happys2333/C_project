



#include "../Header/OpenGUI_frame.h"

bool OPENGUI_Init = true;

void CFrame::visualize() {
    window = glfwCreateWindow(width,height,title.c_str(), nullptr,nullptr);
    if(window==nullptr){
        std::cout<<"Error: Failed to create an Window"<<std::endl;
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit()!=GLEW_OK)//在调用opengl函数之前初始化glad，
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        exit(1);
    }
    glfwSetWindowPos(window,x,y);
    glViewport(x,y,width,height);
    glClearColor(Background_red,Background_green,Background_blue,Background_alpha);//清空屏幕
    glClear(GL_COLOR_BUFFER_BIT);// 清空缓冲区
    glfwSwapBuffers(window);
    if(ExitButton!=-10){
        glfwSetKeyCallback(window,keyCallback);
    }
    mainloop();
}

CFrame::CFrame(unsigned int weight, unsigned int height, unsigned int x, unsigned int y, std::string title) {
    initial();
    this->width=weight;
    this->height=height;
    this->x = x;
    this->y = y;
    this->title = title;
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
    CTextBoxlist.free();
    CLabellist.free();
    bool Big = false;
    GLFWwindow *window;
}

void CFrame::mainloop() {
    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();
    }
    glfwTerminate();
}

void CFrame::Setsize(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
}

void CFrame::ReNewWindow() {
    glViewport(x,y,width,height);
}
void CFrame::setExitButton(int button) {
    ExitButton = button;
}


void CFrame::addLable(const CLabel &l) {

}

void CFrame::addButton(const CButton &b) {

}

void CFrame::addTextBox(const CTextBox &t) {
    CTextBoxlist.add(t);
}

bool CFrame::isPress(int button) {
    return glfwGetKey(window,button)==GLFW_PRESS;
}

void CFrame::PressTodo(int button) {

}

void CFrame::key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if(key == ExitButton && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window,GLFW_TRUE);
    }
}

void CFrame::addin() {

}

void CFrame::setBackgroundColor(int red, int green, int blue, int alpha) {
    this->Background_red = red;
    this->Background_green = green;
    this->Background_blue = blue;
    this->Background_alpha = alpha;
}






