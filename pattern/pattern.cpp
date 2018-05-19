//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  pattern.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 17 Apr 2018 09:23:14 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "pattern.h"

void buildCell(Cell(&C))
{
	C.data[0] = rand() % 256;
	C.data[1] = rand() % 256;
	C.data[2] = rand() % 256;
}

void buildWorld(Cell (&world)[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			buildCell(world[i][j]);
		}
	}
}

void addLife(Cell (&world)[HEIGHT][WIDTH])
{
	if (ADD_LIFE == 1)
	{
		for (int i = 0; i < ADD_CNT; ++i)
		{
			int x = rand() % HEIGHT;
			int y = rand() % WIDTH;
			buildCell(world[x][y]);
		}
	}
}

void generate(Cell (&world)[HEIGHT][WIDTH], int time)
{
	for (int k = 0; k < time; ++k)
	{
		Cell temp[HEIGHT][WIDTH];
		for (int i = 0; i < HEIGHT; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{
				calcOne(world, i, j);
			}
		}
		for (int i = 0; i < HEIGHT; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{
				world[i][j] = temp[i][j];
			}
		}
		addLife(world);
	}
}

void calcOne(Cell (&world)[HEIGHT][WIDTH], int x, int y)
{
	int pos[SIZE][SIZE][2];
	for (int i = -1; i < 2; ++i)
	{
		for (int j = -1; j < 2; ++j)
		{
			pos[i + 1][j + 1][0] = (x + i + HEIGHT) % HEIGHT;
			pos[i + 1][j + 1][1] = (y + j + WIDTH) % WIDTH;
		}
	}
	changeOne(world, pos);
}

void changeOne(Cell (&world)[HEIGHT][WIDTH], int pos[SIZE][SIZE][2])
{
	float sum = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			/* code */
		}
	}
}

float checkTable(Cell A, Cell B)
{
	return 0.1;
}

void actionOne(Cell A, Cell B)
{
	float temp = checkTable(A, B);
}

int surive(int num, int type)
{
	if (num == 3)
	{
		return 1;
	}
	else if (num == 2)
	{
		return type;
	}
	else
	{
		return 0;
	}
}

void printCell(Cell(&C))
{
	printf("(%3d %3d %3d)\t", C.data[0], C.data[1], C.data[2]);
}

void printWorld(Cell (&world)[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			printCell(world[i][j]);
		}
		printf("\n");
	}
}
