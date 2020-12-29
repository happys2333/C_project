cmake_minimum_required(VERSION 3.12)
project(OpenGUI)
if(APPLE)
    message(STATUS "Welcome to use OpenGUI, your system is MacOS!")
else()
    message(FATAL_ERROR "We haven't supported your system yet")
endif()
set(CMAKE_CXX_STANDARD 14)
set(OpenGL_Path ./OpenGL)#local opengl path
message(STATUS "Finding the OpenGL...")


if(OpenGL_Path)
    message(STATUS "Found the OpenGL")
else()
    message(FATAL_ERROR "No OpenGL found!")
endif()
message(STATUS "Linking to the library...")
set(GLEW_H ./OpenGL/glew/2.2.0/include/GL)
set(GLFW_H ./OpenGL/glfw/3.3.2/include/GLFW)

message(STATUS "Creating the Library...")
add_library(OpenGUI Frame/OpenGUI_frame.h Frame/OpenGUI_frame.cpp Frame/OpenGUI_Button.cpp Frame/OpenGUI_Button.h Frame/OpenGUI_label.cpp Frame/OpenGUI_label.h Frame/OpenGUI_TextBox.cpp Frame/OpenGUI_TextBox.h Top/OpenGUI.cpp Top/OpenGUI.h Frame/Func.h)
message(STATUS "Linking the OpenGL...")


message(STATUS "Enjoy your GUI trip")