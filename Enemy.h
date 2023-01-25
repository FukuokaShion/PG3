#pragma once
#include<stdio.h>

class Enemy{
protected:
public:
	Enemy();
	~Enemy();
	void Initialize();

	void Update();

	static int num;
	static bool isAllAlive;

	bool isAlive;
	
};