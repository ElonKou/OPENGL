//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  life.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 13 Apr 2018 11:31:01 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <GL/glut.h>
#include <cstdio>
#include "lib.h"

using namespace std;
#ifndef TRAIN
#define LOOP_CNT 2000000
#endif
int world[HEIGHT][WIDTH];

void init(void){
	glClearColor(0.09, 0.09, 0.09, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, WIDTH * SIZE, 0, HEIGHT * SIZE);
}

void drawGraid(){
	// glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.07, 0.07, 0.07);
	int a[] = {0, 0};
	int b[] = {WIDTH * SIZE, 0};
	int c[] = {WIDTH * SIZE, 0};
	int d[] = {0, 0};
	for (int i = 0; i <= HEIGHT / GRAID_SIZE; ++i)
	{
		a[1] = i * SIZE * GRAID_SIZE;
		b[1] = i * SIZE * GRAID_SIZE;
		c[1] = i * SIZE * GRAID_SIZE + SIZE;
		d[1] = i * SIZE * GRAID_SIZE + SIZE;
		glBegin(GL_POLYGON);
		glVertex2iv(a);
		glVertex2iv(b);
		glVertex2iv(c);
		glVertex2iv(d);
		glEnd();
	}
	int e[] = {0, 0};
	int f[] = {0, 0};
	int g[] = {0, WIDTH * SIZE};
	int h[] = {0, WIDTH * SIZE};
	for (int i = 0; i <= WIDTH / GRAID_SIZE; ++i)
	{
		e[0] = i * SIZE * GRAID_SIZE;
		f[0] = i * SIZE * GRAID_SIZE + SIZE;
		g[0] = i * SIZE * GRAID_SIZE + SIZE;
		h[0] = i * SIZE * GRAID_SIZE;
		glBegin(GL_POLYGON);
		glVertex2iv(e);
		glVertex2iv(f);
		glVertex2iv(g);
		glVertex2iv(h);
		glEnd();
	}

	// glFlush();
}

void drawCube(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	int a[] = {800,500};
	int b[] = {800,510};
	int c[] = {810,510};
	int d[] = {810,500};
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2iv(a);
	glVertex2iv(d);
	glVertex2iv(c);
	glVertex2iv(b);
	glEnd();
	glFlush();
}

void drawLife(int (&world)[HEIGHT][WIDTH]){
	glClear(GL_COLOR_BUFFER_BIT);
	drawGraid();
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (world[i][j] == 1)
			{
				int a[] = {j * SIZE, i * SIZE};
				int b[] = {a[0] + SIZE, a[1]};
				int c[] = {a[0] + SIZE, a[1] + SIZE};
				int d[] = {a[0], a[1] + SIZE};
				glBegin(GL_POLYGON);
				glVertex2iv(a);
				glVertex2iv(b);
				glVertex2iv(c);
				glVertex2iv(d);
				glEnd();
			}
		}
	}
	glFlush();
}


void loop(void){
	for (int i = 0; i < LOOP_CNT; ++i)
	{
		generate(world, GENERATION);
		drawLife(world);
		// drawGraid();
		// drawCube();
		// printWorld(world);
	}
}

int main(int argc, char * argv[]){
	buildWorld(world);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(WIDTH * SIZE, HEIGHT * SIZE);
	glutInitWindowPosition((WINDOW_WIDTH - WIDTH * SIZE) / 2,(WINDOW_HEIGHT - HEIGHT * SIZE) / 2);
	glutCreateWindow("ELonkou Game life");

	init();
	glutDisplayFunc(loop);
	glutMainLoop();
	
    return 0;
}

