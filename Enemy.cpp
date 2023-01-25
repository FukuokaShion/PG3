#include "Enemy.h"

int Enemy::num;


Enemy::Enemy() {
	num++;
	printf("“G%d\n", num);
}

Enemy::~Enemy() {
	num--;
}

void Enemy::AllFallDown() {
	if (num == 0){
		printf("‘S‚Ä‚Ì“G‚ğíœ\n");
	}
}