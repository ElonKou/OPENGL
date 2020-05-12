#!/bin/bash

g++ vertexColor.cc -I../common ../common/Window.cc ../common/Buffer.cc ../common/Shader.cc -O3 -o vertexColor -lGLEW -lglfw -lGL -std=c++11
