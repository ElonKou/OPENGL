/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : coordinate.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Sat 25 Apr 2020 11:12:25 AM CST
================================================================*/

#include "Buffer.hh"
#include "Shader.hh"
#include "Texture.hh"
#include "Window.hh"
#include <iomanip>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void print(glm::mat4 mat) {
    for (size_t j = 0; j < 4; j++) {
        for (size_t i = 0; i < 4; i++) {
            std::cout << mat[j][i] << "\t";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[]) {
    Window  window;
    Buffer  buffer;
    Shader  shader("./vertex.glsl", "./fragment.glsl");
    Texture texture_1("../resources/mmmm.jpg");
    Texture texture_2("../resources/face.png");
    texture_1.Bind();
    texture_2.Bind();

    // std::vector<GLfloat> vertices = {
    //     -0.5, -0.5, -0.5, //
    //     -0.5, -0.5, 0.5,  //
    //     -0.5, 0.5, 0.5,   //
    //     -0.5, 0.5, -0.5,  //
    //     0.5, -0.5, -0.5,  //
    //     0.5, -0.5, 0.5,   //
    //     0.5, 0.5, 0.5,    //
    //     0.5, 0.5, -0.5    //
    // };

    std::vector<GLfloat> vertices = {
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, //
        0.5f, -0.5f, -0.5f, 1.0f, 0.0f,  //
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,   //
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,   //
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,  //
        -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, //

        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, //
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,  //
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,   //
        0.5f, 0.5f, 0.5f, 1.0f, 1.0f,   //
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,  //
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, //

        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,   //
        -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,  //
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, //
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, //
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  //
        -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,   //

        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,   //
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,  //
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f, //
        0.5f, -0.5f, -0.5f, 0.0f, 1.0f, //
        0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  //
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,   //

        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, //
        0.5f, -0.5f, -0.5f, 1.0f, 1.0f,  //
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,   //
        0.5f, -0.5f, 0.5f, 1.0f, 0.0f,   //
        -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,  //
        -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, //

        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, //
        0.5f, 0.5f, -0.5f, 1.0f, 1.0f,  //
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,   //
        0.5f, 0.5f, 0.5f, 1.0f, 0.0f,   //
        -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,  //
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f  //
    };
    glm::vec3 positions[] = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(2.0f, 5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f, 3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f, 2.0f, -2.5f),
        glm::vec3(1.5f, 0.2f, -1.5f),
        glm::vec3(-1.3f, 1.0f, -1.5f)};

    shader.Use();
    buffer.BindBufferPointer(vertices, {}, {3, 2});
    shader.Set1i("texture_1", 0);
    shader.Set1i("texture_2", 1);

    while (!window.Closed()) {
        window.Clear();

        for (size_t i = 0; i < 10; i++) {
            float     angle   = glfwGetTime();
            glm::mat4 model   = glm::mat4(1.0f);
            glm::mat4 view    = glm::mat4(1.0f);
            glm::mat4 project = glm::mat4(1.0f);
            model             = glm::translate(model, positions[i]);
            model             = glm::rotate(model, angle, glm::vec3(0.5f, 1.0f, 0.0f));
            view              = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
            project           = glm::perspective(glm::radians(45.0f), (float)window.width / (float)window.height, 0.1f, 100.0f);
            shader.SetMat4f("model", model);
            shader.SetMat4f("view", view);
            shader.SetMat4f("project", project);

            buffer.Bind();
            buffer.Draw();
        }

        window.Swap();
        window.PollEvents();
    }
    window.Terminate();
    return 0;
}
