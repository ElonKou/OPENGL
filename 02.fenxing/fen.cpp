//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  fen.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 06 Apr 2018 05:10:11 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <GL/glut.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <queue>
using namespace std;

#ifndef NUM
#define NUM 3
#endif

struct Pos
{
	float x,y;
};
struct Seg
{
	Pos start;
	Pos vec;
	Pos points[NUM];
};

queue<Seg> Q;

void changeOne(Seg s,Pos start, Pos p){
	float a = p.x / s.vec.x;
	float b = p.y / s.vec.y;
	q = Q.front()
	point = new Seg()
	point.posX = start.x;
	point.posY = start.y;
	for (int i = 0; i < NUM; ++i)
	{
		point[i].x = q.points[i] * a;
		point[i].y = q.points[i] * b;
	}
	Q.pop();
	Q.push(point) 
}



void init(){
	// glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 960.0, 0.0, 540.0);
	// glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);  
}

void lineSegment(){
	glClear(GL_COLOR_BUFFER_BIT);
	float x1 = 100.0f;
	float y1 = 100.0f;
	float x2 = 800.0f;
	float y2 = 100.0f;
	float x3 = 800.0f;
	float y3 = 800.0f;
	float x4 = 100.0f;
	float y4 = 800.0f;

	
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();

	glBegin(GL_POINTS);
	float x,y;

	for (int i = 0; i < 20000; ++i)
	{
		glColor3f(1.0,1.0,1.0);
		int temp = rand()%4;
		if (temp == 0)
		{
			x = (x + x1) / 2.0;
			y = (y + y1) / 2.0;
			glVertex2f(x,y);
		}
		if (temp == 1)
		{
			x = (x + x2) / 2.0;
			y = (y + y2) / 2.0;
			glVertex2f(x,y);
		}
		if (temp == 2)
		{
			x = (x + x3) / 2.0;
			y = (y + y3) / 2.0;
			glVertex2f(x,y);
		}
		if (temp == 3)
		{
			x = (x + x4) / 2.0;
			y = (y + y4) / 2.0;
			glVertex2f(x,y);
		}
	}

	glEnd();
	glFlush();
}

int main(int argc, char *argv[]){
	changeOne();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(960, 540);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Elonkou test");
	
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
	
	return 0;
}


