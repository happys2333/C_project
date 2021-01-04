# CS205 C/C++ Final Project——OpenGUI

## 概况

![license](https://img.shields.io/badge/license-MIT-yellowgreen)![language](https://img.shields.io/badge/language-C%2B%2B-brightgreen)![author](https://img.shields.io/badge/author-happys-blue)![support](https://img.shields.io/badge/Supported--platform-macOS-red)
#### 使用库：OpenGL glfw glew
##### 测试平台：`macOS BigSur`
### 版本号：v1.00
## C++程序设计课程期末大作业，基于OpenGL实现的macOS专属UI开发库

由于时间较为紧张，本库可能以后会作为我*个人项目*独立出来继续开发，但是目前我们仅实现部分功能

# 目录
- [使用方法](#使用方法)       	
- [功能简介](#功能简介)      	
- [代码框架](#代码框架)      	
- [运行效果](#运行效果)     	
- [版本变动](#版本变动)
# 功能简介
本版程序目的希望实现在macOS下使用C++可以十分流畅自然的编写一套可以随时套用的图形化界面库，避免任何可能因此导致冗余的问题        
本程序完全基于C++代码开发，并不使用XML等描述性语言。
初代版本计划实现的内容为四个模块：创建窗口，添加按钮，实现文本显示，实现鼠标键盘交互，下面对四个方面进行依次的讲解开发，并讲解我们的易用性。
- **完美的cmake使用**            
本项目为了所有使用库的用户考虑，尽可能将我们的CMake编写较为详细，让您可以无忧使用本库。          
如下cmake可以让您在遇到各种情况下
```cmake
cmake_minimum_required(VERSION 3.12)
project(OpenGUI)
if(APPLE)
    message(STATUS "Welcome to use OpenGUI, your system is MacOS!")
else()
    message(FATAL_ERROR "We haven't supported your system yet")
endif()
set(CMAKE_CXX_STANDARD 14)
message(STATUS "Your path is ${PROJECT_SOURCE_DIR}")
set(OpenGL_Path ${PROJECT_SOURCE_DIR}/OpenGL)#local opengl path
message(STATUS "Finding the OpenGL...")
if(OpenGL_Path)
    message(STATUS "Found the OpenGL")
else()
    message(FATAL_ERROR "No OpenGL found!")
endif()
message(STATUS "Linking to the library...")
set(GLEW_H ${PROJECT_SOURCE_DIR}/OpenGL/glew/2.2.0/include/GL)
set(GLFW_H ${PROJECT_SOURCE_DIR}/OpenGL/glfw/3.3.2/include/GLFW)
set(GLTOOLS_H ${PROJECT_SOURCE_DIR}/OpenGL/GLTools)
include_directories(${GLTOOLS_H} ${GLFW_H} ${GLEW_H})
message(STATUS "Creating the Library...")
set(GLEW_LIB ${PROJECT_SOURCE_DIR}/OpenGL/glew/2.2.0/lib/libGLEW.2.2.dylib)
set(GLFW_LIB ${PROJECT_SOURCE_DIR}/OpenGL/glfw/3.3.2/lib/libglfw.3.dylib)
set(GLTOOLS_LIB ${PROJECT_SOURCE_DIR}/OpenGL/GLTools/libgltools.dylib)
link_libraries(${OPENGL} ${GLFW_LIB} ${GLTOOLS_LIB} ${GLEW_LIB})
add_library(OpenGUI Header/OpenGUI_frame.h Frame/OpenGUI_frame.cpp Frame/OpenGUI_Button.cpp Header/OpenGUI_Button.h Frame/OpenGUI_label.cpp Header/OpenGUI_label.h Frame/OpenGUI_TextBox.cpp Header/OpenGUI_TextBox.h Header/Func.h Header/GUIroot.h Header/KeyBorad.h Header/Color.h)
message(STATUS "Linking the OpenGL...")
target_link_libraries(OpenGUI "-framework OpenGL")
target_link_libraries(OpenGUI "-framework GLUT")
message(STATUS "Enjoy your GUI trip")
```
- 创建窗口              
您可以很简单的绘制一个简单的窗口    
使用如下的窗口绘制函数可以让您很简单的绘制一个窗口。
我们使用CFrame为本程序的




- 添加按钮

- 文本加入

- 鼠标键盘交互
# 使用方法
### 本程序目前只支持macOS下的运行，程序自带代码库支持macOS Bigsur版本，如果非此版本的，请将您版本对应的*OpenGL*安装后替换程序下的lib中的文件即可。
经常更新您的macOS系统将会让您在编程的路上一路顺风               
我们给出两种运行本程序的方法：
- 使用已经编译好的程序库，将release下的OpenGUI文件拷贝到您的工程项目下
- 进入我们的sorce文件下使用如下命令
```shell
cmake .
make
```
将获得的libOpenGUI.a和Header文件夹放入您的工程目录

# 代码框架

# 运行效果
- 使用很简单的代码即可绘制您想要的图形界面
例如一个800x600的窗口
![img1](img/win1.png)
或者一个200x200的窗口
![img2](img/win2.png)
当然您可以看出我们可以非常方便的
# 版本变动
- v 1.00:此版本作为程序第一次可以正常运行的初代版本，功能尚不完善
