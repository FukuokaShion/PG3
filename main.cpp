#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<memory>
#include<list>

#include"Enemy.h"

bool Enemy::isDead;

int	main() {

	int select;
	const int enemyMax = 2;
	std::list<std::unique_ptr<Enemy>>enemys_;

	for (size_t i = 0; i < enemyMax; i++){
		std::unique_ptr<Enemy> newEnemy = std::make_unique<Enemy>();
		enemys_.push_back(std::move(newEnemy));

	}

	while (true)
	{
		printf("1‚©2‚ð‘I‘ð\n");
		scanf_s("%d", &select);

		if (select == 1 || select == 2)
		{
			Enemy::isDead = true;

		}else {
			printf("1‚©2ˆÈŠO‚Í“ü—Í‚Å‚«‚Ü‚¹‚ñ\n");

		}

		if (Enemy::isDead){
			enemys_.remove_if([](std::unique_ptr<Enemy>& enemy) { return Enemy::isDead; });
			Enemy::AllFallDown();
			break;
		}

	}


	system("Pause");

	return	0;
}