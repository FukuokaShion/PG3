#include "Enemy.h"

int Enemy::num;

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::Initialize() {
	isAlive = true;
	num++;
}

void Enemy::Update() {
	
	if (isAlive == false) {
		isAllAlive = false;
	}

	if(isAllAlive==false) {
		isAlive = false;
	}


}
