#!/bin/bash

g++ transform.cc -I../common ../common/Window.cc  ../common/Texture.cc ../common/Buffer.cc ../common/Shader.cc -O3 -o transform -lGLEW -lglfw -lGL -std=c++11
