//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  triangle.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 05 May 2018 12:27:13 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define WIDTH 960
#define HEIGHT 540
#define WIN_TITLE "Triangle."

// 编译了链接库
// -lGLEW -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

// 顶点着色器
const GLchar *vertexshaderOrangesource = "#version 330 core\n"
                                         "layout (location = 0) in vec3 position;\n"
                                         "void main()\n"
                                         "{\n"
                                         "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                                         "}\n\0";

const GLchar *fragmentshader1source = "#version 330 core\n"
                                      "out vec4 color;\n"
                                      "void main()\n"
                                      "{\n"
                                      "color = vec4(1.0f, 0.4f, 0.7f, 1.0f);\n"
                                      "}\n\0";

const GLchar *fragmentshader2source = "#version 330 core\n"
                                      "out vec4 color;\n"
                                      "void main()\n"
                                      "{\n"
                                      "color = vec4(0.3f, 1.0f, 0.5f, 1.0f);\n"
                                      "}\n";

int main()
{
    // glfw的初始化
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    // 窗口创建
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, WIN_TITLE, nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create window." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // glew初始化
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to init the glew." << std::endl;
    }
    // 视口初始化
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // 设置键盘事件
    glfwSetKeyCallback(window, key_callback);

    // 1.创建顶点着色器的对象
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexshaderOrangesource, NULL);
    glCompileShader(vertexShader);
    // 2.检查是否编译成功以及返回错误信息
    GLint success;
    GLchar infolog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infolog << std::endl;
    }
    // 3.片断着色
    GLuint fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
    GLuint fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderOrange, 1, &fragmentshader1source, NULL);
    glShaderSource(fragmentShaderYellow, 1, &fragmentshader2source, NULL);
    glCompileShader(fragmentShaderOrange);
    glCompileShader(fragmentShaderYellow);
    glGetShaderiv(fragmentShaderYellow, GL_COMPILE_STATUS, &success);
    // 4.检查片段着色是否成功以及返回信息
    glGetShaderiv(fragmentShaderOrange, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderOrange, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED_ORANGE\n"
                  << infolog << std::endl;
    }
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderYellow, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED_YELLOW\n"
                  << infolog << std::endl;
    }
    // 5.创建着色器对象,并且链接编译
    GLuint shaderProgramOrange = glCreateProgram();
    glAttachShader(shaderProgramOrange, vertexShader);
    glAttachShader(shaderProgramOrange, fragmentShaderOrange);
    glLinkProgram(shaderProgramOrange);

    GLuint shaderProgramYellow = glCreateProgram();
    glAttachShader(shaderProgramYellow, vertexShader);
    glAttachShader(shaderProgramYellow, fragmentShaderYellow);
    glLinkProgram(shaderProgramYellow);

    // 6.检查链接是否成功,返回信息
    glGetProgramiv(shaderProgramOrange, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgramOrange, 512, NULL, infolog);
        std ::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED_ORANGE\n"
                   << infolog << std::endl;
    }
    glGetProgramiv(shaderProgramYellow, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgramYellow, 512, NULL, infolog);
        std ::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED_YELLOW\n"
                   << infolog << std::endl;
    }
    // 7.删除已经链接的着色器
    glDeleteShader(shaderProgramOrange);
    glDeleteShader(fragmentShaderOrange);
    glDeleteShader(fragmentShaderYellow);
    // 8.顶点着色器
    GLfloat vertices[] = {
        -0.5f,
        -0.5f,
        0.0f,
        0.5f,
        -0.5f,
        0.0f,
        0.0f,
        0.5f,
        0.0f,
    };
    GLfloat verticesYellow[] = {
        0.5f,
        -0.5f,
        0.0f,
        0.3f,
        0.7f,
        0.0f,
        0.0f,
        0.5f,
        0.0f,
    };
    GLuint VBO[2], VAO[2];
    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);
    // 9.绑定顶点缓冲数据
    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    // 另一个对象
    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesYellow), verticesYellow, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    // 进入绘制图像循环
    while (!glfwWindowShouldClose(window))
    {
        // 检查是否有触发事件
        // 清理屏幕颜色
        // 交换颜色缓冲
        glfwPollEvents();
        glClearColor(0.12f, 0.12f, 0.12f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgramOrange);
        glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glUseProgram(shaderProgramYellow);
        glBindVertexArray(VAO[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }
    // 游戏结束,释放资源
    glDeleteVertexArrays(2, VAO);
    glDeleteBuffers(2, VAO);
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}