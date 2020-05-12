//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  texture.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 19 May 2018 06:52:31 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "Buffer.hh"
#include "Shader.hh"
#include "Texture.hh"
#include "Window.hh"
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main() {
    Window  window;
    Buffer  buffer;
    Shader  shader("./vertex.glsl", "./frag.glsl");
    Texture texture("../resources/mmmm.jpg");

    std::vector<GLfloat> vertices = {
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // Top Right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
        -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f   // Top Left
    };
    std::vector<GLuint> indices = {
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };

    // shader.Use();
    buffer.BindBufferPointer(vertices, indices, {3, 3, 2});

    while (!window.Closed()) {
        window.Clear();

        buffer.Bind();
        texture.Bind();
        shader.Use();

        glm::mat4 rotation;
        glm::mat4 translate;
        float     value = glfwGetTime();
        float     x     = glm::sin(value) * 0.5;
        float     y     = glm::cos(value) * 0.5;
        rotation        = glm::rotate(rotation, (GLfloat)value, glm::vec3(0.0f, 0.0f, 1.0f));
        translate       = glm::translate(translate, glm::vec3(x, y, 0.0f));
        shader.SetMat4f("rotation", rotation);
        shader.SetMat4f("translate", translate);

        buffer.Draw();

        window.Swap();
        window.PollEvents();
    }

    window.Terminate();
    return 0;
}
