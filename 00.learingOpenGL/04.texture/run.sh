#!/bin/bash

g++ texture.cc -I../common ../common/Window.cc  ../common/Texture.cc ../common/Buffer.cc ../common/Shader.cc -O3 -o texture -lGLEW -lglfw -lGL -std=c++11
