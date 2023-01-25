#include "Enemy.h"
#include <stdio.h>

Enemy::Enemy(){
}

Enemy::~Enemy(){
}

void Enemy::Initialize(){
	phaseNum = 0;
}

void Enemy::Update(){
	(this->*pFuncTable[phaseNum])();

	phaseNum++;
	
	if (phaseNum > 2) {
		phaseNum = 0;
	}
}

void Enemy::Approach(){
	printf("Ú‹ß\n");
}

void Enemy::Shooting(){
	printf("UŒ‚\n");
}

void Enemy::Secession(){
	printf("—£’E\n");
}

void (Enemy::* Enemy::pFuncTable[])() ={
	&Enemy::Approach,
	&Enemy::Shooting,
	&Enemy::Secession,
};