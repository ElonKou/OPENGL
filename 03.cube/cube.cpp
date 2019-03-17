//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  cube.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 07 Apr 2018 08:23:08 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
using namespace std; 
  
#define WIN32_LEAN_AND_MEAN  
  
//#pragma comment(lib, "openGL32.lib")  
//#pragma comment(lib, "glu32.lib")  
//#pragma comment(lib, "glaux.lib")  
float angle=0.0f;  
HDC g_HDC;  
float legAngle[2]={0.0f,0.0f};  
float armAngle[2]={0.0f,0.0f};  
float ambientLight[]={0.1f,0.3f,0.8f,1.0f};  //环境光  
float diffuseLight[]={0.25f,0.25f,0.25f,1.0f}; //散射光  
float lightPosition[]={0.0f,0.0f,1.0f,0.0f}; //光源位置  
//材质变量  
float matAmbient[]={1.0f,1.0f,1.0f,1.0f};  
float matDiff[]={1.0f,1.0f,1.0f,1.0f};  
//初始化  
void Initialize()  
{  
 glClearColor(0.0f,0.0f,0.0f,0.0f);   //清理颜色为黑色  
 glShadeModel(GL_SMOOTH);     //使用平滑明暗处理  
 glEnable(GL_DEPTH_TEST);     //剔除隐藏面  
 glEnable(GL_CULL_FACE);      //不计算多边形背面  
 glFrontFace(GL_CCW);      //多边形逆时针方向为正面  
 glEnable(GL_LIGHTING);      //启用光照  
 //为LIGHT0设置析质  
 glMaterialfv(GL_FRONT,GL_AMBIENT,matAmbient);  
 glMaterialfv(GL_FRONT,GL_DIFFUSE,matDiff);  
 //现在开始调协LIGHT0  
 glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight); //设置环境光分量  
 glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight); //设置散射光分量  
 glLightfv(GL_LIGHT0,GL_POSITION,lightPosition); //设置光源在场景中的位置  
 //启用光  
 glEnable(GL_LIGHT0);  
}  
//绘制单位立方体  
void DrawCube(float xPos,float yPos,float zPos)  
{  
 glPushMatrix();  
  glTranslatef(xPos,yPos,zPos);  
  glBegin(GL_QUADS);    //顶面  
  glNormal3f(0.0f,1.0f,0.0f);  
  glVertex3f(0.5f,0.5f,0.5f);  
  glVertex3f(0.5f,0.5f,-0.5f);  
  glVertex3f(-0.5f,0.5f,-0.5f);  
  glVertex3f(-0.5f,0.5f,0.5f);  
  glEnd();  
  glBegin(GL_QUADS);    //底面  
  glNormal3f(0.0f,-1.0f,0.0f);  
  glVertex3f(0.5f,-0.5f,0.5f);  
  glVertex3f(-0.5f,-0.5f,0.5f);  
  glVertex3f(-0.5f,-0.5f,-0.5f);  
  glVertex3f(0.5f,-0.5f,-0.5f);  
  glEnd();  
  glBegin(GL_QUADS);    //前面  
  glNormal3f(0.0f,0.0f,1.0f);  
  glVertex3f(0.5f,0.5f,0.5f);  
  glVertex3f(-0.5f,0.5f,0.5f);  
  glVertex3f(-0.5f,-0.5f,0.5f);  
  glVertex3f(0.5f,-0.5f,0.5f);  
  glEnd();  
  glBegin(GL_QUADS);    //背面  
  glNormal3f(0.0f,0.0f,-1.0f);  
  glVertex3f(0.5f,0.5f,-0.5f);  
  glVertex3f(0.5f,-0.5f,-0.5f);  
  glVertex3f(-0.5f,-0.5f,-0.5f);  
  glVertex3f(-0.5f,0.5f,-0.5f);  
  glEnd();  
  glBegin(GL_QUADS);    //左面  
  glNormal3f(-1.0f,0.0f,0.0f);  
  glVertex3f(-0.5f,0.5f,0.5f);  
  glVertex3f(-0.5f,0.5f,-0.5f);  
  glVertex3f(-0.5f,-0.5f,-0.5f);  
  glVertex3f(-0.5f,-0.5f,0.5f);  
  glEnd();  
  glBegin(GL_QUADS);    //右面  
  glNormal3f(1.0f,0.0f,0.0f);  
  glVertex3f(0.5f,0.5f,0.5f);  
  glVertex3f(0.5f,-0.5f,0.5f);  
  glVertex3f(0.5f,-0.5f,-0.5f);  
  glVertex3f(0.5f,0.5f,-0.5f);  
  glEnd();  
 glPopMatrix();  
}  
//处理场景的绘制  
void Render()  
{  
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //清理颜色/深度缓存  
 glLoadIdentity();     //复位旋转角度计数器  
 angle=angle+0.1f;     //递增旋转角度计数器  
 if(angle>=360.0f)     //如果已旋转一周,复位计数器  
  angle=0.0f;  
 glTranslatef(0.0f,0.0f,-3.0f);  
 glRotatef(angle,1.0f,0.0f,0.0f);  
 glRotatef(angle,0.0f,1.0f,0.0f);  
 glRotatef(angle,0.0f,0.0f,1.0f);  
 DrawCube(0.0f,0.0f,0.0f);  
 glFlush();         
 SwapBuffers(g_HDC);     //交换前后缓存  
}  
//为设备环境设置像素格式的函数  
void SetupPixelFormat(HDC hDC)  
{  
 int nPixelFormat;  
 static PIXELFORMATDESCRIPTOR pfd=  
 {  
  sizeof(PIXELFORMATDESCRIPTOR),  
   1,  
   PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER,  
   PFD_TYPE_RGBA,  
   32,  
  0,0,0,0,0,0,  
  0,  
  0,  
  0,  
  0,0,0,0,  
  16,  
  0,  
  0,  
  PFD_MAIN_PLANE,  
  0,  
  0,0,0  
 };  
 nPixelFormat=ChoosePixelFormat(hDC,&pfd);  
 SetPixelFormat(hDC,nPixelFormat,&pfd);  
}  
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)  
{  
 static HGLRC hRC;  
 static HDC hDC;  
 int width,height;  
 switch(message)  
 {  
 case WM_CREATE:  
  hDC=GetDC(hwnd);  
  g_HDC=hDC;  
  SetupPixelFormat(hDC);  
  hRC=wglCreateContext(hDC);  
  wglMakeCurrent(hDC,hRC);  
  return 0;  
  break;  
    
 case WM_CLOSE:  
  wglMakeCurrent(hDC,NULL);  
  wglDeleteContext(hRC);  
  PostQuitMessage(0);  
  return 0;  
  break;  
    
 case WM_SIZE:  
  height=HIWORD(lParam);  
  width=LOWORD(lParam);  
  if(height==0)  
   height=1;  
  glViewport(0,0,width,height);  
  glMatrixMode(GL_PROJECTION);  
  glLoadIdentity();  
  gluPerspective(54.0f,(GLfloat)width/(GLfloat)height,1.0f,1000.0f);  
  glMatrixMode(GL_MODELVIEW);  
  glLoadIdentity();  
  return 0;  
  break;  
 default:  
  break;  
 }  
 return (DefWindowProc(hwnd,message,wParam,lParam));  
}  
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)  
{  
 WNDCLASSEX windowClass;  
 HWND hwnd;  
 MSG msg;  
 bool done;  
 int width=800;  
 int height=600;  
 int bits=32;  
 windowClass.cbSize=sizeof(WNDCLASSEX);  
 windowClass.style=CS_HREDRAW|CS_VREDRAW;  
 windowClass.lpfnWndProc=WndProc;  
 windowClass.cbClsExtra=0;  
 windowClass.cbWndExtra=0;  
 windowClass.hInstance=hInstance;  
 windowClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);  
 windowClass.hCursor=LoadCursor(NULL,IDC_ARROW);  
 windowClass.hbrBackground=NULL;  
 windowClass.lpszMenuName=NULL;  
 windowClass.lpszClassName="MyClass";  
 windowClass.hIconSm=LoadIcon(NULL,IDI_WINLOGO);  
 if(!RegisterClassEx(&windowClass))  
  return 0;  
 hwnd=CreateWindowEx(WS_EX_APPWINDOW|WS_EX_WINDOWEDGE,  
  "MyClass",  
  "OpenGL Cube",  
  WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN|WS_CLIPSIBLINGS,  
  0,0,  
  800,600,  
  NULL,  
  NULL,  
  hInstance,  
  NULL);  
 if(!hwnd)  
  return 0;  
 ShowWindow(hwnd,SW_SHOW);  
 UpdateWindow(hwnd);  
 Initialize();  //初始化绘制环境  
 done=false;  
 while(!done)  
 {  
  PeekMessage(&msg,hwnd,NULL,NULL,PM_REMOVE);  
  if(msg.message==WM_QUIT)  
  {  
   done=true;  
  }  
  else  
  {  
   Render();  
   TranslateMessage(&msg);  
   DispatchMessage(&msg);  
  }  
 }  
 return msg.wParam;  
}  

