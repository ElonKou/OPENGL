#pragma once
#ifndef GLFW_WINDOW_H_
#define GLFW_WINDOW_H_

// #define WINDOW_WIDTH 960
// #define WINDOW_HEIGHT 540
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <string>

void MouseCallbackFunc(GLFWwindow* window, int button, int action, int mode);

void MousePosCallbackFunc(GLFWwindow* window, double x, double y);

void KeyboardCallbackFunc(GLFWwindow* window, int key, int scan, int action, int mode);

void ResizeWindowCallbackFunc(GLFWwindow* window, int w, int h);

class Window {
  private:
    GLFWwindow* window;

    std::string window_name;

    int fps;

  public:
    static int width;

    static int height;

    Window();

    ~Window();

    bool Closed();

    void PollEvents();

    void Swap();

    void SetInterval(int frame_rate);

    void Clear();

    void Terminate();
};

#endif