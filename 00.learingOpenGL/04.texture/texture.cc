//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  texture.cc
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 19 May 2018 06:52:31 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "Buffer.hh"
#include "Shader.hh"
#include "Texture.hh"
#include "Window.hh"
#include <iostream>
#include <vector>

int main() {
    Window  window;
    Shader  shader("../shaders/text_vertex.vs", "../shaders/text_fragment.fs");
    Texture texture_1("../resources/mmmm.jpg");
    Texture texture_2("../resources/face.png");
    Buffer  buffer;

    std::vector<GLfloat> vertices = {
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 2.0f, 2.0f,   // Top Right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
        -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 2.0f   // Top Left
    };
    std::vector<GLuint> indices = {
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };
    shader.Use();
    shader.Set1i("ourTexture1", 0);
    shader.Set1i("ourTexture1", 1);

    buffer.BindBufferPointer(vertices, indices, {3, 3, 2});
    while (!window.Closed()) {
        window.Clear();

        texture_1.Bind();
        texture_2.Bind();
        buffer.Bind();
        buffer.Draw();

        window.Swap();
        window.PollEvents();
    }
    window.Terminate();
    return 0;
}
