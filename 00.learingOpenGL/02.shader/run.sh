#!/bin/bash

g++ multi_triangle.cc -I../common ../common/Window.cc ../common/Buffer.cc ../common/Shader.cc -O3 -o multi_triangle -lGLEW -lglfw -lGL -std=c++11
