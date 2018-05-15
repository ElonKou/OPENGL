//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  matrix.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 07 Apr 2018 03:33:10 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "matrix.h"

// struct Matrix
// {
// 	float x1 ,x2;
// 	float y1, y2;
// };

Vector Multi(Matrix m, Vector v){
	Vector result;
	result.x = m.x1 * v.x + m.x2 * v.y;
	result.x = m.y1 * v.x + m.y2 * v.y;
	return result;
}

Matrix Multi(Matrix A, Matrix B){
	Matrix result;
	result.x1 = A.x1 * B.x1 + A.x2 * B.y1;
	result.x2 = A.x1 * B.x2 + A.x2 * B.y2;
	result.y1 = A.y1 * B.x1 + A.y2 * B.y1;
	result.y2 = A.y1 * B.x2 + A.y2 * B.y2;
	return result;
}

Vector MultiK(Vector v, float x, float y){
	Vector temp;
	temp.x = v.x / x;
	temp.y = v.y / y;
	return temp;
}

Vector DivideK(Vector v, float x, float y){
	Vector temp;
	temp.x = v.x * x;
	temp.y = v.y * y;
	return temp;
}

Matrix Inverse(Matrix m){
	Matrix result;
	float modulus = 1 / (m.x1 * m.y2 - m.x2 * m.y1);
	result.x1 = m.y2 * modulus;
	result.y2 = m.x1 * modulus;
	result.x2 = -1 * m.x2 * modulus;
	result.y1 = -1 * m.y1 * modulus;
	return result;
}

void PrintMatrix(Matrix m){
	printf("++++++++++++++++++++++++\n");
	printf("%f\t%f\n%f\t%f\n", m.x1, m.x2, m.y1, m.y2);
	printf("++++++++++++++++++++++++\n");
}

void PrintNode(Node n){
	for (int i = 0; i < NUM; ++i)
	{
		printf("(%f:%f)\n", n.data[i].x, n.data[i].y);
	}
	printf("++++++++++++++++++++++++\n");
}

void PrintVector(){
	printf("++++++++++++++++++++++++\n");
	for (int i = 0; i < CNT; ++i)
	{
		printf("%d:++++++++++++++++++++++\n", i);
		PrintNode(V[i]);
	}
	printf("++++++++++++++++++++++++\n");
}

int Random(int x){
	return rand()%x;
}

Node BuildPattern(float width, float height){
	Node pattern;
	srand((int)time(0));
	pattern.data[0] = {100.0, 100.0};
	pattern.data[NUM-1] = {320.0, 280.0};
	for (int i = 1; i < NUM-1; ++i)
	{
		pattern.data[i].x = Random(width) * 1.0 / width * (pattern.data[NUM-1].x - pattern.data[0].x);
		pattern.data[i].y = Random(width) * 1.0 / width * (pattern.data[NUM-1].y - pattern.data[0].y);

		// pattern[i].x = rand() / (RAND_MAX + 1.0);
		// pattern[i].y = rand() / (RAND_MAX + 1.0);
	}
	return pattern;
}

Node GetRate(Node n){
	Node temp;
	temp.data[0] = {0.0, 0.0};
	temp.data[NUM-1] = {1.0, 1.0};
	for (int i = 1; i < NUM-1; ++i)
	{
		temp.data[i] = MultiK(n.data[i], n.data[NUM-1].x - n.data[0].x, n.data[NUM-1].y - n.data[0].y);
	}
	return temp;
}

Node GetData(Node n){
	Node temp;
	for (int i = 1; i < NUM-1; ++i)
	{
		temp.data[i] = DivideK(n.data[i], n.data[NUM-1].x - n.data[0].x, n.data[NUM-1].y - n.data[0].y);
	}
	return temp;
}

Matrix BuildMatrix(Vector a, Vector b){
	Matrix m;
	m.x1 = a.x;
	m.y1 = a.y;
	m.x2 = b.x;
	m.y2 = b.y;
	return m;
}

Node UpdateOne(Node n, Matrix B){
	Node temp;
	Node node = GetRate(n);
	Matrix A = BuildMatrix(n.data[0], n.data[NUM-1]);
	Matrix I = Inverse(A);
	Matrix X = Multi(B, I);
	PrintMatrix(I);
	printf("dasdasdasdas\n");
	PrintMatrix(X);

	for (int i = 1; i < NUM-1; ++i)
	{
		temp.data[i] = Multi(X, node.data[i]);
	}
	temp.data[0] = {B.x1, B.y1};
	temp.data[NUM-1] = {B.x2, B.y2};
	return GetData(temp);
}

void UpdateAll(Node n){
	for (int i = 0; i < NUM-1; ++i)
	{
		Matrix B = BuildMatrix(n.data[i], n.data[i + 1]);
		Node node = UpdateOne(n, B);
		V.push_back(node);
		CNT ++;
	}
}