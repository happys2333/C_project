//#include <glfw3.h>
//#include <cstring>
//
//#include <ft2build.h>
//#include FT_FREETYPE_H
//unsigned char* img;
//#include<opencv2/opencv.hpp>
//GLint width=480 ,height=320;
//void readImage(const char* filename){
//
//}
//void DrawImage(const char *filename)
//{
//
//}
//void drawTriangle()
//{
//    int Cwidth=100,Cheight=100;
//    int x=50,y=60;
//    float picx,picy;
//    float pirx = (float)2/(float)width,piry = (float)2/(float)height;
//    picx = (-1+(float)x*pirx);
//    picy = (1-(float)y*piry);
//    float addx=(float)Cwidth*pirx,addy=(float)Cheight*piry;
//    glClearColor (1, 1, 1, 1);
//    glClear (GL_COLOR_BUFFER_BIT);
//    glBegin(GL_QUADS);
//
//    glColor3f(0, 0.0, 0.0);    // Red
//    glVertex3f(picx, picy, 0.0);
//
//    glColor3f(0.0, 0, 0.0);    // Green
//    glVertex3f(picx+addx, picy, 0.0);
//
//    glColor3f(0.0, 0.0, 0);    // Blue
//    glVertex3f(picx+addx, picy+addy, 0.0);
//
//    glColor3f(0, 0.0, 0);    // Blue
//    glVertex3f(picx, picy+addy, 0.0);
//    glEnd();
//}
//int main(void)
//{
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(480, 320, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//unsigned char * c = new unsigned char[200*300*4];
//for(int i = 0; i < 200;i++){
//    for(int j=0;j<300*4;j+=4){
//        c[j+i*30]=1;
//        c[j+i*30+1]=0;
//        c[j+i*30+2]=0;
//        c[j+i*30+3]=0;
//
//    }
//}
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /*your draw*/
////         drawPoint();
////         drawLint();
////         drawTriangle();
//        glClearColor (1, 1, 1, 1);
//        glClear (GL_COLOR_BUFFER_BIT);
//        glRasterPos2i(100,100);
//        glDrawPixels(200,300, GL_RGBA, GL_UNSIGNED_BYTE, c);
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}
#include <OpenGUI_label.hpp>
#include <OpenGUI_frame.hpp>
#include <OpenGUI_Button.hpp>
#include <KeyBorad.hpp>
bool Test1(){
    using namespace std;
    cout << "Testing1"<<endl;
    return true;
}
bool Test2(){
    using namespace std;
    cout << "Testing2"<<endl;
    return true;
}
int main(){
    CFrame test(1024,800,0,0,"Happys");
    test.setExitButton(KEY_ESCAPE);
    test.setBackgroundColor(1,1,0,0);
    CButton button("hi",50,30,800,200);
    CButton button2("hi",50,30,800,300);
    button.setBackgroundColor(0,0,0,0);
    button.SetButtonFun(Test1);
    button2.setBackgroundColor(1,1,1,1);
    button2.SetButtonFun(Test2);
    test.addButton(button);
    test.addButton(button2);
    CLabel label("../img/test.bmp",true,100,0,640,640);
    test.addLable(label);
    test.visualize();
}

//#include <glew.h>
////#include <glfw3.h>
////#include <iostream>
////
////void curse_poscallback(GLFWwindow *window, double x, double y)
////{
////    std::cout << "(pos:" << x << "," << y << ")" << std::endl;
////}
////
////int main()
////{
////    glfwInit();
////    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 使用core-profile这行代码很重要
////    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
////    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
////    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
////    GLFWwindow *window = glfwCreateWindow(480, 270, "LearningOpenGL", nullptr, nullptr);
////    if (!window)
////    {
////        std::cout << "Filed to create window." << std::endl;
////        glfwTerminate();
////        return -1;
////    }
////    glfwMakeContextCurrent(window);
////    // 使用回调函数
////    glfwSetCursorPosCallback(window, curse_poscallback);
////    glewExperimental = GL_TRUE;
////    if (glewInit() != GLEW_OK)
////    {
////        std::cout << "Failed to create glew." << std::endl;
////        return -1;
////    }
////    int width=480, height=270;
////
////    glViewport(0, 0, width, height);
////    while (!glfwWindowShouldClose(window))
////    {
////        glfwPollEvents();
////        glClearColor(1.4f, 0.5f, 0.3f, 1.0f);
////        glClear(GL_COLOR_BUFFER_BIT);
////        glfwSwapBuffers(window);
////    }
////    glfwTerminate();
////    return 0;
////}
// Std. Includes
