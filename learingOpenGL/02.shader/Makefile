# shader : shader.o
# 	g++ -o shader shader.o -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -std=c++11
# 	rm -rf shader.o

priticeTwo : priticeTwoTriangles.o
	g++ -o priticeTwoTriangles priticeTwoTriangles.o -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -std=c++11



priticeTwoTriangles.o : priticeTwoTriangles.cpp
	g++ -c priticeTwoTriangles.cpp -std=c++11

shader.o : shader.cpp 
	g++ -c shader.cpp -std=c++11