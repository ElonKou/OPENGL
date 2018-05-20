//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  main.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 05 May 2018 12:24:56 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Compile file path: -lGLEW -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    std::cout << "(key:" << key << " action:" << action << " scancode:" << scancode << " mode:" << mode << ")" << std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
    {
        std::cout << "(" << 0 << "," << 0 << ")" << std::endl;
    }
}

void mouse_callback(GLFWwindow *window, int button, int action, int mode)
{
    std::cout << "(button:" << button << " action:" << action << " mode:" << mode << ")" << std::endl;
}

void curse_poscallback(GLFWwindow *window, double x, double y)
{
    std::cout << "(pos:" << x << "," << y << ")" << std::endl;
}

int main()
{
    // 初始化窗口.
    glfwInit();
    // 配置主要版本
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // 使用核心模式,不允许用户调整窗口大小
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    // 创建窗口
    GLFWwindow *window = glfwCreateWindow(480, 270, "LearningOpenGL", nullptr, nullptr);
    if (!window)
    {
        std::cout << "Filed to create window." << std::endl;
        glfwTerminate();
        return -1;
    }
    // 上下文的设置
    glfwMakeContextCurrent(window);
    // 键盘点击事件的回调函数的注册使用
    glfwSetKeyCallback(window, key_callback);
    // 鼠标的点击事件注册
    glfwSetMouseButtonCallback(window, mouse_callback);
    glfwSetCursorPosCallback(window, curse_poscallback);
    // glew管理OpenGL的函数指针,因此在使用事前需要进行对其初始化.
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to create glew." << std::endl;
        return -1;
    }
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    std::cout << "(" << width << "," << height << ")" << std::endl;
    // 设置窗口的
    glViewport(0, 0, width, height);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(1.4f, 0.5f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
