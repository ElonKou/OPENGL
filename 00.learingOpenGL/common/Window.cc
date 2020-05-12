/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : Window.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Sun 19 Apr 2020 01:09:18 PM CST
================================================================*/

#include "Window.hh"

void MouseCallbackFunc(GLFWwindow* window, int button, int action, int mode) {
    std::cout << "button: " << button << " acction: " << action << " mode: " << mode << std::endl;
}

void MousePosCallbackFunc(GLFWwindow* window, double x, double y) {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

void KeyboardCallbackFunc(GLFWwindow* window, int key, int scan, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        // std::cout << "key: " << key << " scan: " << scan << " acction: " << action << " mode: " << mode << std::endl;
        glfwSetWindowShouldClose(window, true);
    }
}

void ResizeWindowCallbackFunc(GLFWwindow* window, int w, int h) {
    glViewport(0, 0, w, h);
}

int Window::width  = WINDOW_WIDTH;
int Window::height = WINDOW_HEIGHT;

Window::Window() {
    window_name = "LearnOpenGL";

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
    if (!window) {
        std::cout << "Error create window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    // glfwSetMouseButtonCallback(window, MouseCallbackFunc);
    // glfwSetCursorPosCallback(window, MousePosCallbackFunc);
    glfwSetFramebufferSizeCallback(window, ResizeWindowCallbackFunc);
    glfwSetKeyCallback(window, KeyboardCallbackFunc);

    glewExperimental = GL_TRUE;
    glewInit();
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    // glViewport(0, 0, WINDOW_HEIGHT, WINDOW_HEIGHT);
    glEnable(GL_DEPTH_TEST);
}

Window::~Window() {
}

bool Window::Closed() {
    return glfwWindowShouldClose(window);
}

void Window::PollEvents() {
    glfwPollEvents();
}

void Window::Swap() {
    glfwSwapBuffers(window);
}

void Window::SetInterval(int frame_rate) {
    glfwSwapInterval(frame_rate);
}

void Window::Clear() {
    glClearColor(0.12f, 0.12f, 0.12f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Window::Terminate() {
    glfwTerminate();
}