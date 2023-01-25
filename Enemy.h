#pragma once
#include<stdio.h>

class Enemy{
protected:
public:
	Enemy();
	~Enemy();
	void Initialize();

	void Update();

	void Approach();
	void Shooting();
	void Secession();

private:

	static void (Enemy::* pFuncTable[])();
	int phaseNum = 0;
	
};