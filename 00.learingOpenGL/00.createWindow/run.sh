#!/bin/bash

g++ -I../common window.cc ../common/Window.cc -lGL -lGLEW -lglfw -std=c++11 -o window
