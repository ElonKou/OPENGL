//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  lib.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 21 Apr 2018 07:03:59 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <random>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "lib.h"

int randomInt()
{
	// srand((unsigned)time(0));
	//std::random_device rd;
	return rand();
	//return random();
}

int randomInt(int end)
{
	return randomInt() % end;
}

int randomInt(int start, int end)
{
	return randomInt(end - start) + start;
}
