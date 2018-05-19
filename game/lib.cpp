//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  lib.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 13 Apr 2018 11:31:19 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "lib.h"

void buildWorld(int (&world)[HEIGHT][WIDTH]){
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			world[i][j] = rand() % 2;
		}
	}
}

void addLife(int (&world)[HEIGHT][WIDTH]){
	if (ADD_LIFE == 1)
	{
		for (int i = 0; i < ADD_CNT; ++i)
		{
			int x = rand() % HEIGHT;
			int y = rand() % WIDTH;
			world[x][y] = 1;
		}
	}
}

void generate(int (&world)[HEIGHT][WIDTH], int time){
	for (int k = 0; k < time; ++k)
	{
		int temp [HEIGHT][WIDTH];
		for (int i = 0; i < HEIGHT; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{
				temp[i][j] = calcOne(world ,i, j);
			}
		}
		for (int i = 0; i < HEIGHT; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{
				world[i][j] = temp[i][j];
			}
		}
		//addLife(world);
	}
}

int calcOne(int (&world)[HEIGHT][WIDTH],int x, int y){
	int sum = 0;
	for (int i = -1; i < 2; ++i)
	{
		for (int j = -1; j < 2; ++j)
		{
			sum += world[(x + i + HEIGHT) % HEIGHT][(y + j + WIDTH) % WIDTH];
		}
	}
	sum -= world[x][y];
	return surive(sum,world[x][y]);
}

int surive(int num, int type){
	if (num == 4 || (num == 6))
	{
		return 1;
	}else if (num == 3 || num == 2 || num == 0)
	{
		return type;
	}else
	{
		return 0;
	}
}

void printWorld(int (&world)[HEIGHT][WIDTH]){
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			printf("%d", world[i][j]);
		}
		printf("\n");
	}
}











