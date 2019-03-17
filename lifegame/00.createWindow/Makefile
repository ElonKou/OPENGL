window : window.o
	g++ -o window window.o -lGLEW -lglfw -lGL
	rm *.o

window.o:window.cpp
	g++ -c window.cpp -o window.o -std=c++11

clean:
	rm *.o
