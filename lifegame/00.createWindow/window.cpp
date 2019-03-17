//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File   :window.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 02 Jan 2019 02:49:09 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

void refreshWindow(float i) {
    glClearColor(i, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void quit_callback(GLFWwindow* window,
                   int key,
                   int scannode,
                   int action,
                   int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    GLFWwindow* window =
        glfwCreateWindow(800, 600, "LearnOPenGL", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, quit_callback);

    glewExperimental = GL_TRUE;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    float i;
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
        refreshWindow(i);
    }
    glfwTerminate();
    return 0;
}
