#pragma once
#include<stdio.h>

class Enemy{
protected:

public:
	Enemy();

	~Enemy();

	static void AllFallDown();
	static int num;
	static bool isDead;
};