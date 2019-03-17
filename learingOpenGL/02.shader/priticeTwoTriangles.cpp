#include <iostream>
#include <GL/glew.h>
#include <cmath>
#include <GLFW/glfw3.h>

#define WIN_WIDTH 960
#define WIN_HEIGHT 540

void keyCall(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        std::cout << "(key:" << key
                  << ", action:" << action
                  << ", scancode:" << scancode
                  << ", mode:" << mode << ")"
                  << std::endl;
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
const GLchar *vertexShaderSource = "#version 330 core\n"
                                   "layout (location = 0) in vec3 position;\n"
                                   "out vec4 vertexColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                                   "vertexColor = vec4(position, 1.0);\n"
                                   "}\0";

const GLchar *oriangeShaderSource = "#version 330 core\n"
                                    "out vec4 color;\n"
                                    "uniform vec4 ourColor;\n"
                                    "void main()\n"
                                    "{\n"
                                    // "color = vec4(1.0f, 0.4f, 0.4f, 1.0f);\n"
                                    "color = ourColor;\n"
                                    "}\n\0";

const GLchar *yellowShaderSource = "#version 330 core\n"
                                   "in vec4 vertexColor;\n"
                                   "uniform vec4 ourColor;\n"
                                   "out vec4 color;\n"
                                   "void main()\n"
                                   "{\n"
                                //    "color = vec4(0.4f, 1.0f, 0.4f, 1.0f);\n"
                                   "color = vertexColor;\n"
                                   "}\n";

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow *window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "twoTiriangleWindow", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCall);
    glewExperimental = GL_TRUE;
    glewInit();
    int width;
    int height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // infoLog
    GLint success;
    GLchar infoLog[512];
    // vertex-shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED:\n"
                  << infoLog << std::endl;
    }
    // fragment-shader-oriange
    GLuint oriangeShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(oriangeShader, 1, &oriangeShaderSource, NULL);
    glCompileShader(oriangeShader);
    glGetShaderiv(oriangeShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(oriangeShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::GRAGMENT::COMPILATION_FAILED:\n"
                  << infoLog << std::endl;
    }
    // fragment-shader-yellow
    GLuint yellowShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(yellowShader, 1, &yellowShaderSource, NULL);
    glCompileShader(yellowShader);
    glGetShaderiv(yellowShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(yellowShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::GRAGMENT::COMPILATION_FAILED:\n"
                  << infoLog << std::endl;
    }
    // oriange-programshader
    GLuint oriangeProgram = glCreateProgram();
    glAttachShader(oriangeProgram, vertexShader);
    glAttachShader(oriangeProgram, oriangeShader);
    glLinkProgram(oriangeProgram);
    glGetProgramiv(oriangeProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(oriangeProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED:\n"
                  << infoLog << std::endl;
    }
    // yellow-programshader
    GLuint yellowProgram = glCreateProgram();
    glAttachShader(yellowProgram, vertexShader);
    glAttachShader(yellowProgram, yellowShader);
    glLinkProgram(yellowProgram);
    // delete the shader
    glDeleteShader(vertexShader);
    glDeleteShader(oriangeShader);
    glDeleteShader(yellowShader);
    // Set data.
    GLfloat first[] = {
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f};
    GLfloat second[] = {
        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f};
    GLuint VBOS[2];
    GLuint VAOS[2];
    glGenVertexArrays(2, VAOS);
    glGenBuffers(2, VBOS);

    // bind,bind,data,pointer,open vertexattr,debind.
    glBindVertexArray(VAOS[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOS[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(first), first, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid *)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    glBindVertexArray(VAOS[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOS[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(second), second, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    // glEnable(GL_MULTISAMPLE);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.12, 0.12, 0.12, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(oriangeProgram);

        GLfloat timeValue = glfwGetTime();
        GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
        GLfloat redValue = (cos(timeValue) / 2) + 0.5;
        GLfloat blueValue = (atan(timeValue) / 3.14) + 0.5;
        std::cout << "green:" << greenValue << std::endl;
        GLint vertextColorLocation = glGetUniformLocation(oriangeProgram, "ourColor");
        glUniform4f(vertextColorLocation, redValue, greenValue, blueValue, 1.0f);

        glBindVertexArray(VAOS[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(yellowProgram);
        glBindVertexArray(VAOS[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }
    glDeleteVertexArrays(2, VAOS);
    glDeleteBuffers(2, VBOS);
    glfwTerminate();
    return 0;
}
