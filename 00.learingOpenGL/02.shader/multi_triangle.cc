#include "Buffer.hh"
#include "Shader.hh"
#include "Window.hh"
#include <vector>

int main() {
    Window window;
    Shader orangeShader("../shaders/multi_vert.vs", "../shaders/multi_orange_frag.fs");
    Shader yellowShader("../shaders/multi_vert.vs", "../shaders/multi_yellow_frag.fs");
    Buffer orange_buffer;
    Buffer yellow_buffer;

    std::vector<GLfloat> first{
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f};

    std::vector<GLfloat> second = {
        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f};

    orange_buffer.BindBufferPointer(first, {}, {3});
    yellow_buffer.BindBufferPointer(second, {}, {3});

    while (!window.Closed()) {
        window.Clear();
        window.PollEvents();

        float timeValue  = glfwGetTime();
        float greenValue = (sin(timeValue) / 2) + 0.5;
        float redValue   = (cos(timeValue) / 2) + 0.5;
        float blueValue  = (atan(timeValue) / 3.14) + 0.5;

        orangeShader.Use();
        // orangeShader.Set4f("ourColor", redValue, 1.0 - redValue, blueValue, 1.0f);
        orange_buffer.Bind();
        orange_buffer.Draw();

        yellowShader.Use();
        yellow_buffer.Bind();
        yellow_buffer.Draw();

        window.Swap();
    }

    window.Terminate();
    return 0;
}
