//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File Name: main.cpp
// Author   : ElonKou
// Email    : elonkou@ktime.cc
// Date     : 2019年03月17日 星期日 18时03分04秒
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <GL/glut.h>
#include <cstdio>
#include <iostream>
#include "../lib/core.h"

using namespace std;
#ifndef TRAIN
#define LOOP_CNT 2000000
#endif
int world[HEIGHT][WIDTH];

void init(void) {
    glClearColor(0.09, 0.09, 0.09, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WIDTH * SIZE, 0, HEIGHT * SIZE);
}

void offset(int *arr, int x, int y) {
    // arr[0] += x;
    // arr[1] += y;
    // if (arr[0] >= WINDOW_WIDTH) {
    //     arr[0] -= WINDOW_WIDTH;
    // }
    // if (arr[1] >= WINDOW_HEIGHT) {
    //     arr[1] -= WINDOW_HEIGHT;
    // }
}

void drawGraid(int offsetX, int offsetY) {
    // glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.07, 0.07, 0.07);
    int a[] = {0, 0};
    int b[] = {WIDTH * SIZE, 0};
    int c[] = {WIDTH * SIZE, 0};
    int d[] = {0, 0};
    for (int i = 0; i <= HEIGHT / GRAID_SIZE; ++i) {
        a[1] = i * SIZE * GRAID_SIZE;
        b[1] = i * SIZE * GRAID_SIZE;
        c[1] = i * SIZE * GRAID_SIZE + SIZE;
        d[1] = i * SIZE * GRAID_SIZE + SIZE;
        glBegin(GL_POLYGON);
        // offset(a, 0, offsetY);
        // offset(b, 0, offsetY);
        // offset(c, 0, offsetY);
        // offset(d, 0, offsetY);
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
    for (int i = 0; i <= WIDTH / GRAID_SIZE; ++i) {
        e[0] = i * SIZE * GRAID_SIZE;
        f[0] = i * SIZE * GRAID_SIZE + SIZE;
        g[0] = i * SIZE * GRAID_SIZE + SIZE;
        h[0] = i * SIZE * GRAID_SIZE;
        glBegin(GL_POLYGON);
        // offset(e, offsetX, 0);
        // offset(f, offsetX, 0);
        // offset(g, offsetX, 0);
        // offset(h, offsetX, 0);
        glVertex2iv(e);
        glVertex2iv(f);
        glVertex2iv(g);
        glVertex2iv(h);
        glEnd();
    }
    // glFlush();
}

void drawCube() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    int a[] = {800, 500};
    int b[] = {800, 510};
    int c[] = {810, 510};
    int d[] = {810, 500};
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2iv(a);
    glVertex2iv(d);
    glVertex2iv(c);
    glVertex2iv(b);
    glEnd();
    // glFlush();
}

void drawLife(int (&world)[HEIGHT][WIDTH], int offsetX, int offsetY) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGraid(offsetX, offsetY);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (world[i][j] == 1) {
                int a[] = {j * SIZE, i * SIZE};
                // int b[] = {a[0] + SIZE, a[1]};
                // int c[] = {a[0] + SIZE, a[1] + SIZE};
                // int d[] = {a[0], a[1] + SIZE};
                offset(a, offsetX, offsetY);
                glPointSize(SIZE);
                glBegin(GL_POINTS);
                glVertex2f(a[0], a[1]);
                // glBegin(GL_POLYGON);
                // glVertex2iv(a);
                // glVertex2iv(b);
                // glVertex2iv(c);
                // glVertex2iv(d);
                glEnd();
            }
        }
    }
    glutSwapBuffers();
    // glFlush();
}

void loop(void) {
    int offsetX = 100;
    int offsetY = 100;
    generate(world, GENERATION);
    drawLife(world, offsetX, offsetY);

    // drawGraid();
    // drawCube();
    // printWorld(world);
}

void loopOne(int x) {
    loop();
    glutTimerFunc(25, loopOne, 1);
}

void mouseClick(int btn, int state, int x, int y) {
    printf("点击了鼠标，btn:%d,state:%d,x:%d,y:%d\n", btn, state, x, y);
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        printf("按下了左边按钮\n");
    }
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        printf("松开了左边按钮\n");
    }
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        printf("按下了右边按钮\n");
    }
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        printf("松开了右边按钮\n");
    }
}
void mouseMove(int x, int y) { printf("移动鼠标中，x:%d,y%d\n", x, y); }

int main(int argc, char *argv[]) {
    buildWorld(world);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(WIDTH * SIZE, HEIGHT * SIZE);
    glutInitWindowPosition((WINDOW_WIDTH - WIDTH * SIZE) / 2,
                           (WINDOW_HEIGHT - HEIGHT * SIZE) / 2);
    glutCreateWindow("ELonkou Game life");

    init();
    // glutMouseFunc(mouseClick);
    // glutMotionFunc(mouseMove);
    // glutDisplayFunc(&loop);
    glutTimerFunc(25, loopOne, 1);
    // glutIdleFunc(&loop);
    glutMainLoop();

    return 0;
}
