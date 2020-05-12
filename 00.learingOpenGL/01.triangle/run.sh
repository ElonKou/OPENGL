#!/bin/bash

g++ triangle.cc ../common/Window.cc ../common/Buffer.cc ../common/Shader.cc -I../common -lGL -lGLEW -lglfw -std=c++11 -o triangle
