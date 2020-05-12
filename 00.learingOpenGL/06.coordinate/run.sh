#!/bin/bash

g++ coordinate.cc -I../common ../common/Texture.cc ../common/Window.cc ../common/Buffer.cc ../common/Shader.cc -lGL -lGLEW -lglfw -std=c++11 -o coordinate