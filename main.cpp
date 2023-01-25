#include <windows.h>
#include "Enemy.h"

int main() {
	Enemy* enemy;
	enemy = new Enemy;
	enemy->Initialize();

	while (true)
	{
		enemy->Update();

		system("pause");
	}

	return 0;
}