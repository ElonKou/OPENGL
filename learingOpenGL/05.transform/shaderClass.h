#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include "shaderClass.h"

class Shader
{
public:
  std::string vertexCode;
  std::string fragmentCode;
  GLuint Program;
  Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
  void Use();
  void Print();
};
#endif