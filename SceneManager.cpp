#include <stdio.h>
#include <Windows.h>
#include "SceneManager.h"

int main() {

	SceneManager* sceneManager = SceneManager::GetInstance();
	int scene = 0;

	while (TRUE) {
		if (scene > 3) {
			scene = 0;
		}

		sceneManager->ChangeScene(scene);
		scene++;
		Sleep(1 * 1000);
	}

	system("pause");
	return 0;

}
