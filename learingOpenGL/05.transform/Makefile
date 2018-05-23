transform : transform.o shaderClass.o
	g++ -o transform transform.o shaderClass.o -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -lSOIL -std=c++11 
	rm transform.o shaderClass.o

transform.o : transform.cpp
	g++ -c transform.cpp -std=c++11

shaderClass.o : shaderClass.cpp
	g++ -c shaderClass.cpp -std=c++11