
#include "../Header/OpenGUI_frame.hpp"

void CFrame::cursorPosCallback(GLFWwindow* window, double x, double y) {
    CFrame* self = static_cast<CFrame*>(glfwGetWindowUserPointer(window));
    if (self) {
        self->mouseX = static_cast<int>(x);
        self->mouseY = static_cast<int>(y);
    }
}

void CFrame::visualize() {
    if (!glfwInit()){
        exit(1);
    }
    GLFWmonitor* monitor = nullptr;
    if (Big) {
        int monitorCount = 0;
        GLFWmonitor** pMonitor = glfwGetMonitors(&monitorCount);
        if (!pMonitor || monitorCount == 0) {
            std::cerr << "Error: No monitors available" << std::endl;
            glfwTerminate();
            exit(1);
        }
        monitor = pMonitor[0];
    }
    window = glfwCreateWindow(width, height, title.c_str(), monitor, nullptr);

    if(window==nullptr){
        std::cout<<"Error: Failed to create an Window"<<std::endl;
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);
    glfwSetWindowPos(window, x, y);
    glfwSetWindowUserPointer(window, this);
    glfwSetCursorPosCallback(window, CFrame::cursorPosCallback);
    mainloop();
}

CFrame::CFrame(GLint width, GLint height, GLint x, GLint y, std::string title) {
    this->width = width;
    this->height = height;
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
    if (window) {
        glfwTerminate();
        window = nullptr;
    }
}

void CFrame::mainloop() {
    while (!glfwWindowShouldClose(window)){
        glClearColor(Background_red, Background_green, Background_blue, Background_alpha);
        glClear(GL_COLOR_BUFFER_BIT);
        if(ExitButton != -10){
            if(isPress(ExitButton)){
                glfwSetWindowShouldClose(window, true);
            }
        }

        for(int i = 0; i < CButtonlist.size(); i++){
            DrawButton(CButtonlist.get(i));
        }

        bool currMousePressed = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS);
        if(currMousePressed && !prevMousePressed){
            for(int j = 0; j < CButtonlist.size(); j++){
                if(CButtonlist.get(j).isClick(mouseX, mouseY)){
                    CButtonlist.get(j).DoButtonFun();
                    break;
                }
            }
        }
        prevMousePressed = currMousePressed;

        for(int i = 0; i < CLabellist.size(); i++){
            CLabellist.get(i).Draw(preX, preY);
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void CFrame::Setsize(GLint width, GLint height) {
    this->width = width;
    this->height = height;
    getPre();
}

void CFrame::ReNewWindow() {
    glViewport(x, y, width, height);
}

void CFrame::setExitButton(int button) {
    ExitButton = button;
}

void CFrame::addLabel(const CLabel &l) {
    CLabellist.add(l);
}

void CFrame::addButton(const CButton &b) {
    CButtonlist.add(b);
}

bool CFrame::isPress(int button) {
    return glfwGetKey(window, button) == GLFW_PRESS;
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
    GLint bx = b.getX(), by = b.getY();
    float Px = (-1+(float)bx*preX);
    float Py = (1-(float)by*preY);
    float r = b.getBackgroundRed(), g = b.getBackgroundGreen(), bl = b.getBackgroundBlue();
    float addx=(float)b.getWidth()*preX, addy=(float)b.getHeight()*preY;
    glBegin(GL_QUADS);
    glColor3f(r, g, bl);
    glVertex3f(Px, Py, 0.0);
    glColor3f(r, g, bl);
    glVertex3f(Px+addx, Py, 0.0);
    glColor3f(r, g, bl);
    glVertex3f(Px+addx, Py+addy, 0.0);
    glColor3f(r, g, bl);
    glVertex3f(Px, Py+addy, 0.0);
    glEnd();
}

void CFrame::getPre() {
    preX = (float)2/(float)width;
    preY = (float)2/(float)height;
}
