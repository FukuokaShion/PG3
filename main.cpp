#include <stdio.h>
#include <Windows.h>
#include "SceneManager.h"

int main() {
	
	SceneManager* sceneManager = SceneManager::GetInstance();
	
	int scene = 0;

	while (TRUE) {
		sceneManager->ChangeScene(scene);

		if (scene < 3) {
			scene++;
		}
		else if (scene >= 3) {
			scene = 0;
		}

		system("pause");
	}

	return 0;

}
