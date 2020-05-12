//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File Name: main.cpp
// Author   : ElonKou
// Email    : elonkou@ktime.cc
// Date     : 2019年03月17日 星期日 18时03分04秒
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "../lib/core.h"
#include <GL/glut.h>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
#ifndef TRAIN
#define LOOP_CNT 2000000
#endif
int  world[HEIGHT][WIDTH];
int  offsetX       = 0;
int  offsetY       = 0;
int  startX        = 0;
int  startY        = 0;
bool leftDown      = false;
bool rightDown     = false;
bool midDown       = false;
bool ctrlDown      = false;
bool playing       = false;
int  size          = SIZE;
int  speed         = 2;
int  tempSpeed     = 0;
int  fps           = 1000 / speed;
int  winX          = (CUR_WIDTH - min(WIDTH * size, CUR_WIDTH)) / 2;
int  winY          = (CUR_HEIGHT - min(HEIGHT * size, CUR_HEIGHT)) / 2;
int  contextWidth  = WIDTH * size;
int  contextHeight = HEIGHT * size;

void updateWindowsOffset() {
    int xx = WIDTH * size;
    int yy = HEIGHT * size;
    winX   = (CUR_WIDTH - xx) / 2;
    winY   = (CUR_HEIGHT - yy) / 2;
    // cout << winX << " " << winY << endl;
}

void init(void) {
    glClearColor(0.09, 0.09, 0.09, 1.0);
    glMatrixMode(GL_PROJECTION);
    // gluOrtho2D(0, WIDTH * SIZE, 0, HEIGHT * SIZE);
    gluOrtho2D(0, CUR_WIDTH, 0, CUR_HEIGHT);
}

void drawGraid(int winX, int winY, int x, int y) {
    // int GRAID_SIZE = GRAID_CNT * SIZE;
    int GRAID_SIZE = contextWidth / GRAID_CNT;
    int wCnt       = contextWidth / GRAID_SIZE;
    int hCnt       = contextHeight / GRAID_SIZE;
    glColor3f(0.07, 0.07, 0.07);
    glLineWidth(size);
    glBegin(GL_LINES);
    x %= GRAID_SIZE;
    y %= GRAID_SIZE;
    // modified the offset for display.
    if (x < 0) {
        x += GRAID_SIZE;
    }
    if (y < 0) {
        y += GRAID_SIZE;
    }
    x += size / 2;
    y += size / 2;
    // hori
    for (int i = 0; i <= hCnt; i++) {
        int start[] = {0 + winX, i * GRAID_SIZE + y + winY};
        int end[]   = {contextWidth + winX, i * GRAID_SIZE + y + winY};
        if (start[1] - winY > contextHeight) {
            continue;
        }
        glVertex2iv(start);
        glVertex2iv(end);
    }
    // vert
    for (int i = 0; i <= wCnt; i++) {
        int start[] = {i * GRAID_SIZE + x + winX, 0 + winY};
        int end[]   = {i * GRAID_SIZE + x + winX, contextHeight + winY};
        if (end[0] - winX > contextWidth) {
            continue;
        }
        glVertex2iv(start);
        glVertex2iv(end);
    }
    glEnd();
    // draw boder
    glColor3f(0.27, 0.27, 0.27);
    int leftDown[]  = {winX - size, winY - size};
    int rightDown[] = {contextWidth + winX + size, winY - size};
    int rightUp[]   = {contextWidth + winX + size, contextHeight + winY + size};
    int leftUp[]    = {winX - size, contextHeight + winY + size};
    glBegin(GL_LINE_LOOP);
    glVertex2iv(leftDown);
    glVertex2iv(rightDown);
    glVertex2iv(rightUp);
    glVertex2iv(leftUp);
    glEnd();
}

void drawLife(int (&world)[HEIGHT][WIDTH], int winX, int winY, int x, int y) {
    if (x <= 0) {
        x %= contextWidth;
        x += contextWidth;
    }
    if (y <= 0) {
        y %= contextHeight;
        y += contextHeight;
    }
    // modified the offset for display.
    x += size / 2;
    y += size / 2;
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(size);
    glBegin(GL_POINTS);
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (world[i][j] == 1) {
                int pos[] = {j * size, i * size};
                pos[0]    = (pos[0] + x) % (WIDTH * size);
                pos[1]    = (pos[1] + y) % (HEIGHT * size);
                pos[0] += winX;
                pos[1] += winY;
                glVertex2iv(pos);
            }
        }
    }
    glEnd();
}

void drawMap(int (&world)[HEIGHT][WIDTH], int winX, int winY, int offsetX,
             int offsetY) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGraid(winX, winY, offsetX, offsetY);
    drawLife(world, winX, winY, offsetX, offsetY);
    glutSwapBuffers();
    // glFlush();
}

void loop(void) {
    updateWindowsOffset();
    if (playing) {
        if (speed >= 100) {
            generate(world, speed / 100);
        } else {
            generate(world, GENERATION);
        }
        drawMap(world, winX, winY, offsetX, offsetY);
    } else {
        drawMap(world, winX, winY, offsetX, offsetY);
    }
}

void loopOne(int x) {
    loop();
    fps = 1000 / speed;
    fps = max(10, fps);
    glutTimerFunc(fps, loopOne, 1);
}

void KeyBoards(unsigned char key, int x, int y) {
    switch (key) {
    case 32:
        cout << "stop" << endl;
        playing = !playing;
        break;
    }
}

void clearByClick(int x, int y) {
    y = CUR_HEIGHT - y;
    x = x - winX - offsetX;
    y = y - winY - offsetY;
    x /= size;
    y /= size;
    x %= WIDTH;
    y %= HEIGHT;
    if (x < 0) {
        x += WIDTH;
    }
    if (y < 0) {
        y += HEIGHT;
    }
    clearOne(world, x, y);
}

void addByClick(int x, int y) {
    y = CUR_HEIGHT - y;
    x = x - winX - offsetX;
    y = y - winY - offsetY;
    x /= size;
    y /= size;
    x %= WIDTH;
    y %= HEIGHT;
    if (x < 0) {
        x += WIDTH;
    }
    if (y < 0) {
        y += HEIGHT;
    }
    addOne(world, x, y);
}

void mouseClick(int btn, int state, int x, int y) {
    // printf("点击了鼠标，btn:%d,state:%d,x:%d,y:%d\n", btn, state, x, y);
    int mod = glutGetModifiers();
    if (mod == GLUT_ACTIVE_CTRL) {
        cout << "CTRL OPEN" << endl;
        ctrlDown = true;
    } else {
        cout << "CTRL CLOSE" << endl;
        ctrlDown = false;
    }
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        cout << "LEFT DOWN" << endl;

        if (ctrlDown) {
            clearByClick(x, y);
        } else {
            addByClick(x, y);
        }
        y        = CUR_HEIGHT - y;
        startX   = x;
        startY   = y;
        leftDown = true;
    }
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        cout << "LEFT UP" << endl;
        y        = CUR_HEIGHT - y;
        startX   = x;
        startY   = y;
        leftDown = false;
    }
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        cout << "RIGHT DOWN" << endl;
        y         = CUR_HEIGHT - y;
        startX    = x;
        startY    = y;
        rightDown = true;
        tempSpeed = speed;
    }
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        cout << "RIGHT UP" << endl;
        y         = CUR_HEIGHT - y;
        startX    = x;
        startY    = y;
        rightDown = false;
        // speed = tempSpeed;
    }
    if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
        cout << "MID DOWN" << endl;
        y       = CUR_HEIGHT - y;
        startX  = x;
        startY  = y;
        midDown = true;
    }
    if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_UP) {
        cout << "MID UP" << endl;
        y       = CUR_HEIGHT - y;
        startX  = x;
        startY  = y;
        midDown = false;
    }
    if (btn == 3 && state == GLUT_UP) {
        cout << "SCROLL UP" << endl;
        size++;
        size          = min(size, 100);
        contextWidth  = WIDTH * size;
        contextHeight = HEIGHT * size;
    }
    if (btn == 4 && state == GLUT_DOWN) {
        cout << "SCROLL DOWN" << endl;
        size--;
        size          = max(size, 1);
        contextWidth  = WIDTH * size;
        contextHeight = HEIGHT * size;
    }
    updateWindowsOffset();
    drawMap(world, winX, winY, offsetX, offsetY);
}
void mouseMove(int x, int y) {
    // printf("移动鼠标中，x:%d,y%d\n", x, y);
    // left: add life
    if (leftDown) {
        if (ctrlDown) {
            cout << "CLEAR" << endl;
            clearByClick(x, y);
        } else {
            cout << "ADD" << endl;
            addByClick(x, y);
        }
    }
    // mid button: move map
    if (midDown) {
        y = CUR_HEIGHT - y;
        offsetX += x - startX;
        offsetY += y - startY;
        startX = x;
        startY = y;
    }
    // right: scale map
    if (rightDown) {
        int temp = (x - startX) / 5;
        if (temp > 0) {
            speed = min(tempSpeed + temp, 1000);
        } else {
            speed = max(tempSpeed + temp, 1);
        }
        cout << "SPEED:" << speed << endl;
    }
    drawMap(world, winX, winY, offsetX, offsetY);
}

int main(int argc, char* argv[]) {
    // buildWorld(world);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(CUR_WIDTH, CUR_HEIGHT);
    glutInitWindowPosition((WINDOW_WIDTH - CUR_WIDTH) / 2,
                           (WINDOW_HEIGHT - CUR_HEIGHT) / 2);
    glutCreateWindow("ELonkou's Gamelife-Lab");
    init();
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMove);
    glutKeyboardFunc(KeyBoards);
    // glutDisplayFunc(&loop);
    glutTimerFunc(fps, loopOne, 1);
    // glutIdleFunc(&loop);
    glutMainLoop();

    return 0;
}
