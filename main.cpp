#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<memory>
#include<list>

#include"Enemy.h"

bool Enemy::isAllAlive = true;

int	main() {

	const int enemyMax = 3;
	Enemy* enemy[enemyMax];
	for (int i = 0; i < enemyMax; i++) {
		enemy[i] = new Enemy();
		enemy[i]->Initialize();
	}


	while (true){
		printf("�G��%d��\n", Enemy::num);

		int select;
		printf("1�`3�œ|�������G�����\n");
		scanf_s("%d", &select);
		enemy[select-1]->isAlive = false;
		printf("%d�̓G��|����\n", select);

		for (int i = 0; i < enemyMax; i++) {
			enemy[i]->Update();
		}

		if (Enemy::isAllAlive == false) {
			printf("�S�Ă̓G��|����\n");
		}

		system("Pause");
	}

	return	0;
}