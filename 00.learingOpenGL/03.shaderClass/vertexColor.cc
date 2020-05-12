#include "Buffer.hh"
#include "Shader.hh"
#include "Window.hh"
#include <vector>

int main() {
    Window window;
    Buffer buffer;

    std::vector<GLfloat> vertices = {
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // right-down
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // left-down
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f};  // mid-up

    // Shader shader = Shader("../shaders/vertex.vs", "../shaders/fragment.fs");
    // Shader shader = Shader("../shaders/diff_vert.vs", "../shaders/diff_frag.fs");
    Shader shader = Shader("../shaders/uniform.vs", "../shaders/uniform.fs");

    buffer.BindBufferPointer(vertices, {}, {3, 3});

    while (!window.Closed()) {
        window.Clear();
        window.PollEvents();

        shader.Use();
        float t = glfwGetTime();
        shader.Set3f("offset", sin(t) * 0.5, cos(t) * 0.5, 1.0f);

        buffer.Bind();
        buffer.Draw();

        window.Swap();
    }
    window.Terminate();
    return 0;
}