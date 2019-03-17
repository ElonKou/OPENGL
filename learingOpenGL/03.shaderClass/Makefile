vertexColor : vertexColor.o shaderClass.o
	g++ -o vertexColor vertexColor.o shaderClass.o -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -std=c++11
	rm vertexColor.o shaderClass.o

vertexColor.o : vertexColor.cpp
	g++ -c vertexColor.cpp -std=c++11

shaderClass.o : shaderClass.cpp
	g++ -c shaderClass.cpp -std=c++11
