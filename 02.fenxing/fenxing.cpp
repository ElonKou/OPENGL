//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  test.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 06 Apr 2018 11:22:42 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

#include <iostream>
#include <GL/glut.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include "matrix.h"

std::vector<Node> V;
int CNT = 0;
Node pattern;

void init(){
	// glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 960.0, 0.0, 540.0);
	// glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);  
}

void lineSegment(){
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	// glColor3f(0.0, 1.0, 0.0);
	// float x,y;
	// Seg q = pattern;
	// print_Seg(q);
	// printf("+++++++++++++++++++++++pattern++++++++++++++++++++++++++++\n");
	// for (int i = 0; i < NUM-1; ++i)
	// {
	// 	glVertex2f(q.points[i].x, q.points[i].y);
	// 	glVertex2f(q.points[i + 1].x, q.points[i + 1].y);
	// 	changeOne(q.points[i], q.points[i + 1]);
	// }
	glEnd();

	glBegin(GL_LINES);
	// glColor3f(0.0, 0.0, 1.0);
	// for (int i = 0; i < NUM-1; ++i)
	// {
	// 	for (int j = 0; j < NUM-1; ++j)
	// 	{
	// 		glVertex2f(V[i].points[j].x, V[i].points[j].y);
	// 		glVertex2f(V[i].points[j + 1].x, V[i].points[j + 1].y);
	// 	}
	// 	print_Seg(V[i]);
	// }
	glEnd();
	glFlush();
}


int main(int argc, char *argv[]){
	pattern = BuildPattern();
	PrintNode(pattern);
	UpdateAll(pattern);
	// PrintVector();

	// glutInit(&argc, argv);
	// glutInitDisplayMode(GLUT_RGB);
	// glutInitWindowSize(960, 540);
	// glutInitWindowPosition(200, 100);
	// glutCreateWindow("Elonkou test");

	// init();
	// glutDisplayFunc(lineSegment);
	// glutMainLoop();
    return 0;
}
