//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  life.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 07 Apr 2018 09:38:29 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <GL/glut.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

void init(){
	// glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	// gluOrtho2D(0.0, 960.0, 0.0, 540.0);
	// glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);  
}

void lineSegment(){
	glClear(GL_COLOR_BUFFER_BIT);

	float x1 = 100.0f;
	float y1 = 100.0f;
	float x2 = 600.0f;
	float y2 = 100.0f;
	float x3 = 800.0f;
	float y3 = 440.0f;
	
    glColor3f(1.0f, 0.0f, 0.0f);    //设置绘图颜色
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);  //绘制矩形

	// glBegin(GL_POINTS);



	// glColor3f(1.0, 0.0, 0.0);
	// glVertex2f(x1,y1);
	// glVertex2f(x2,y2);
	// glVertex2f(x3,y3);
	// glEnd();

	glFlush();
}

int main(int argc, char *argv[]){
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


