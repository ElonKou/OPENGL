texture : texture.o shaderClass.o
	g++ -o texture texture.o shaderClass.o -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -lSOIL -std=c++11 
	rm texture.o shaderClass.o

texture.o : texture.cpp
	g++ -c texture.cpp -std=c++11

shaderClass.o : shaderClass.cpp
	g++ -c shaderClass.cpp -std=c++11