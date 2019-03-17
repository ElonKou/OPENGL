coordinate : coordinate.o shaderClass.o
	g++ -o coordinate coordinate.o shaderClass.o -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -lSOIL -std=c++11 
	rm coordinate.o shaderClass.o

coordinate.o : coordinate.cpp
	g++ -c coordinate.cpp -std=c++11

shaderClass.o : shaderClass.cpp
	g++ -c shaderClass.cpp -std=c++11
