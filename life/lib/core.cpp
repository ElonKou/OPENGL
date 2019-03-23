//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File Name: core.cpp
// Author   : ElonKou
// Email    : elonkou@ktime.cc
// Date     : 2019年03月17日 星期日 18时54分15秒
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "core.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#define random(x) (rand() % x)

int randomInt(int range) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_usec);
    return random(range);
}

void buildWorld(int (&world)[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            world[i][j] = randomInt(2);
        }
    }
}

void addLife(int (&world)[HEIGHT][WIDTH]) {
    if (ADD_LIFE == 1) {
        for (int i = 0; i < ADD_CNT; ++i) {
            int x = randomInt(HEIGHT);
            int y = randomInt(WIDTH) ;
            world[x][y] = 1;
        }
    }
}

void generate(int (&world)[HEIGHT][WIDTH], int time) {
    for (int k = 0; k < time; ++k) {
        int temp[HEIGHT][WIDTH];
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                temp[i][j] = calcOne(world, i, j);
            }
        }
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                world[i][j] = temp[i][j];
            }
        }
        // addLife(world);
    }
}

int calcOne(int (&world)[HEIGHT][WIDTH], int x, int y) {
    int sum = 0;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            sum += world[(x + i + HEIGHT) % HEIGHT][(y + j + WIDTH) % WIDTH];
        }
    }
    sum -= world[x][y];
    return surive(sum, world[x][y]);
}

int surive(int num, int type) {
    if (num == 3) {
        return 1;
    } else if (num == 2) {
        return type;
    } else {
        return 0;
    }
}

void printWorld(int (&world)[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%d", world[i][j]);
        }
        printf("\n");
    }
}
