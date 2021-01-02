//#define GLFW_INCLUDE_GLCOREARB      // 会是glfw包含OpenGL/gl3.h
//#include "glfw3.h"
//
//#include <iostream>
//using std::cout;
//using std::endl;
//#define BUFFER_OFFSET(a) ((void*)(a))
//
//static void errorCallback(int error, const char *des) {
//    fprintf(stderr, "error: %s\n", des);
//}
//
//static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
//        glfwSetWindowShouldClose(window, GLFW_TRUE);
//    }
//}
//
//enum { Triangle, NumVao };
//
//enum { VertexBuffer, NumBuffer };
//
//enum { vPosition = 0, };
//
//GLuint vaos[NumVao];
//GLuint buffers[NumBuffer];
//const GLuint kNumVertices = 6;
//
//GLuint makeShader(GLuint sType, const GLchar *shaderStr) {
//    GLuint shader = glCreateShader(sType);
//    glShaderSource(shader, 1, &shaderStr, NULL);
//    glCompileShader(shader);
//    GLint compiled;
//    glGetShaderiv( shader, GL_COMPILE_STATUS, &compiled );
//    if ( !compiled ) {
//        GLsizei len;
//        glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &len );
//
//        GLchar* log = new GLchar[len];
//        glGetShaderInfoLog( shader, len, &len, log );
//        std::cerr << "shader compilation failed: " << log << std::endl;
//        delete [] log;
//        return 0;
//    }
//    return shader;
//}
//
//void init() {
//    glGenVertexArrays(NumVao, vaos);
//    glBindVertexArray(vaos[Triangle]);
//
//    GLfloat  vertices[kNumVertices][2] = {
//            { -0.90, -0.90 },  // Triangle 1
//            {  0.85, -0.90 },
//            { -0.90,  0.85 },
//            {  0.90, -0.85 },  // Triangle 2
//            {  0.90,  0.90 },
//            { -0.85,  0.90 }
//    };
//
//    glGenBuffers(NumBuffer, buffers);
//    glBindBuffer(GL_ARRAY_BUFFER, buffers[VertexBuffer]);
//    glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);
//
//    const GLchar *vertShaderStr =                 \
//        "#version 410 core                        \n "
//        "layout( location = 0) in vec4 vPosition; \n "
//        "                                         \n "
//        "void main()                              \n "
//        "{                                        \n "
//        "    gl_Position = vPosition;             \n "
//        "}                                        \n "
//    ;
//    GLuint vertShader = makeShader(GL_VERTEX_SHADER, vertShaderStr);
//
//    const GLchar *fragShaderStr =              \
//        "#version 410 core                     \n"
//        "out vec4 fColor;                      \n"
//        "void main()                           \n"
//        "{                                     \n"
//        "   fColor = vec4(0.5, 0.4, 0.8, 1.0); \n"
//        " }                                    \n"
//    ;
//    GLuint fragShader = makeShader(GL_FRAGMENT_SHADER, fragShaderStr);
//
//    GLuint program = glCreateProgram();
//    glAttachShader(program, vertShader);
//    glAttachShader(program, fragShader);
//    glLinkProgram(program);
//    GLint linked;
//    glGetProgramiv( program, GL_LINK_STATUS, &linked );
//    if ( !linked ) {
//        std::cout << "link error" << std::endl;
//        GLsizei len;
//        glGetProgramiv( program, GL_INFO_LOG_LENGTH, &len );
//
//        GLchar* log = new GLchar[len+1];
//        glGetProgramInfoLog( program, len, &len, log );
//        std::cerr << "Shader linking failed: " << log << std::endl;
//        delete [] log;
//    }
//
//    glUseProgram(program);
//
//    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
//    glEnableVertexAttribArray(vPosition);
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBindVertexArray(vaos[Triangle]);
//    glDrawArrays(GL_TRIANGLES, 0, kNumVertices);
//    glFlush();
//}
//
//int main() {
//
//    GLFWwindow *window;
//
//    glfwSetErrorCallback(errorCallback);
//    if (!glfwInit()) {
//        exit(EXIT_FAILURE);
//    }
//
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 使用core-profile这行代码很重要
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
//
//    window = glfwCreateWindow(640, 480, "red", nullptr, nullptr);
//    if (!window) {
//        glfwTerminate();
//        exit(EXIT_FAILURE);
//    }
//
//    glfwSetKeyCallback(window, keyCallback);
//
//    glfwMakeContextCurrent(window);
//
//    cout << "OpenGL Vendor:"    << glGetString(GL_VENDOR)                   << endl;
//    cout << "OpenGL Renderer: " << glGetString(GL_RENDERER)                 << endl;
//    cout << "OpenGL Version: "  << glGetString(GL_VERSION)                  << endl;
//    cout << "GLSL Version:"     << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
//
//    glfwSwapInterval(1);
//
//    init();
//
//    while (!glfwWindowShouldClose(window)) {
//        display();
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
//
//    return 0;
//}
#include <OpenGUI_frame.h>

int main(){
    CFrame frame(800,600,100,100,"OpenGUI_frame");
    frame.setBackgroundColor(1,1,1,1);
    frame.visualize();
    CFrame frame2(200,200,0,0,"second_frame");
    frame2.visualize();

    std::cout<<"hi";
}