/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : triangle.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Thu 09 Apr 2020 11:18:15 PM CST
================================================================*/

#include "Buffer.hh"
#include "Shader.hh"
#include "Window.hh"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    Window window;
    Buffer buffer;
    Shader shader("../shaders/base_vert.vs", "../shaders/base_frag.fs");

    std::vector<GLfloat> vertices = {
        0.5f, -0.5f, 0.0f,  // 2
        0.5f, 0.5f, 0.0f,   // 1
        -0.5f, 0.5f, 0.0f,  // 0
        -0.5f, -0.5f, 0.0f, // 3
        0.5f, -0.5f, 0.0f,  // 5
        -0.5f, 0.5f, 0.0f   // 4
    };
    std::vector<GLuint> indices = {
        0, 1, 2, // first
        0, 2, 3  // second
    };

    buffer.BindBufferPointer(vertices, indices, {3});
    buffer.SetLineMode();
    shader.Use();
    buffer.Bind();
    while (!window.Closed()) {
        window.Clear();
        window.PollEvents();
        buffer.Draw();
        window.Swap();
    }
    window.Terminate();
    return 0;
}
