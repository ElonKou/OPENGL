//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File Name: cc.cpp
// Author   : ElonKou
// Email    : elonkou@ktime.cc
// Date     : 2019年03月17日 星期日 21时09分22秒
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
 
 
/* 函数用来画图 */
void display(void)
{
    cout << "dsds";
}
 
 
/*鼠标点击事件 */
void mouseClick(int btn, int state, int x, int y)
{
    printf("点击了鼠标，btn:%d,state:%d,x:%d,y:%d\n", btn, state, x, y);
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        printf("按下了左边按钮\n");
    }
    if(btn == GLUT_LEFT_BUTTON && state == GLUT_UP){
        printf("松开了左边按钮\n");
    }
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        printf("按下了右边按钮\n");
    }
    if(btn == GLUT_RIGHT_BUTTON && state == GLUT_UP){
        printf("松开了右边按钮\n");
    }
}
 
 
 
/* 鼠标移动事件 */
void mouseMove(int x, int y)
{
    printf("移动鼠标中，x:%d,y%d\n", x, y);
}
 
 
/* 程序入口 */
int main(int argc, char *argv[])
{
    /* 对GLUT进行初始化，并处理所有的命令行参数 */
    glutInit(&argc, argv);
    /* 指定RGB颜色模式和单缓冲窗口 */
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    /* 定义窗口的位置 */
    glutInitWindowPosition(100, 100);
    /* 定义窗口的大小 */
    glutInitWindowSize(400, 400);
    /* 创建窗口，同时为之命名 */
    glutCreateWindow("OpenGL");
    /* 设置窗口清除颜色为白色 */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    /* 参数为一个函数，绘图时这个函数就会被调用 */
    glutDisplayFunc(&display);
    glutIdleFunc(&display);
    /*鼠标点击事件，鼠标点击或者松开时调用 */
    glutMouseFunc(mouseClick);
    /*鼠标移动事件，鼠标按下并移动时调用 */
    glutMotionFunc(mouseMove);
    /* 该函数让GLUT框架开始运行，所有设置的回调函数开始工作，直到用户终止程序为止 */
    glutMainLoop();
    /*程序返回 */
    return(0);
}
