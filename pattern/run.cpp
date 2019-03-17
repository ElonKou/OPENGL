//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  run.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 17 Apr 2018 09:32:23 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <stdio.h>
#include "pattern.h"

Cell world[HEIGHT][WIDTH];

int main(){
	buildWorld(world);
	printWorld(world);
    return 0;
}

