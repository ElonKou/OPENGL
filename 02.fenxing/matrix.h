#include <iostream>
#include <cstdio>
#include <vector>

#ifndef NUM
#define NUM 3
#endif
using namespace std;

struct Vector
{
	float x , y;
};
struct Matrix
{
	float x1 ,x2;
	float y1, y2;
};
struct Node
{
	Vector data[NUM];
};

extern std::vector<Node> V;
extern int CNT;

Vector Multi(Matrix m, Vector v);
Matrix Multi(Matrix A, Matrix B);
Vector MultiK(Vector v, float x, float y);
Vector DivideK(Vector v, float x, float y);
Matrix Inverse(Matrix m);
void printMatrix(Matrix m);
void PrintNode(Node n);
int Random(int x);
Node GetRate(Node n);
Node GetData(Node n);
Matrix BuildMatrix(Vector a, Vector b);
Node UpdateOne(Node n, Matrix B);
Node BuildPattern(float width = 960.0, float height = 540);
void UpdateAll(Node n);
void PrintVector();
