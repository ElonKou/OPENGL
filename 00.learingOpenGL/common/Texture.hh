#pragma once
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "Shader.hh"
#include "stb_image.h"
#include <GL/glew.h>
#include <iostream>
#include <string>

class Texture {
  private:
    static int     cnt;
    unsigned char* image;
    int            width;
    int            height;
    int            channel;
    GLuint         texture;
    int            cur_id;
    int            texture_ids[16];

  public:
    Texture();

    Texture(std::string filename);

    ~Texture();

    void Bind();

    void UnBind();
};

#endif