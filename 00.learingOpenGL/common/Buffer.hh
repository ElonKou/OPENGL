#pragma once
#ifndef BUFFER_H_
#define BUFFER_H_

#include "GL/glew.h"
#include <algorithm>
#include <iostream>
#include <vector>

typedef struct BufferElem {
    GLuint    index;
    GLuint    size;
    GLsizei   stride;
    GLenum    date_type;
    GLboolean normalized;
    void*     pointer;
    BufferElem(GLuint index_, GLuint size_, GLsizei stride_, GLboolean normalized_, GLenum date_type_, void* pointer_)
        : index(index_)
        , size(size_)
        , stride(stride_)
        , normalized(normalized_)
        , date_type(date_type_)
        , pointer(pointer_) {}
    ~BufferElem() {}
} BufferElem;

class Buffer {
  private:
    GLuint                  VAO;
    GLuint                  VBO;
    GLuint                  EBO;
    GLuint                  cnt;
    GLsizei                 stride;
    size_t                  size_VAO;
    size_t                  size_EBO;
    std::vector<BufferElem> elems;

  public:
    Buffer();

    ~Buffer();

    // void BindBufferData(GLenum target, GLfloat* buffer, GLenum usage);

    // void AddAttributePointer(GLenum target, GLuint index, GLint size, GLenum data_type, GLboolean normailzed, GLsizei stride, const void* pointer);

    void BindBufferPointer(GLfloat* pointer, unsigned long ps, GLuint* epointer, unsigned long es, std::vector<GLint> size);

    void BindBufferPointer(std::vector<GLfloat> bpointer, std::vector<GLuint> epointer, std::vector<GLint> size);

    void SetLineMode();

    void Draw();

    void Bind();

    void UnBind();
};

#endif