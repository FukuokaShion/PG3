#include "SceneManager.h"
#include <stdio.h>

SceneManager::SceneManager() {}

SceneManager::~SceneManager() {}


SceneManager* SceneManager::GetInstance(){
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo){
	switch (sceneNo){
	case 0:
		printf("SceneNo:0\n");
		printf("Titleシーン\n");

		break;
	case 1:
		printf("SceneNo:1\n");
		printf("NewGameシーン\n");

		break;
	case 2:
		printf("SceneNo:2\n");
		printf("GamePlayシーン\n");

		break;
	case 3:
		printf("SceneNo:3\n");
		printf("GameClearシーン\n");

		break;
	default:
		break;
	}
}