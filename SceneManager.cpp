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
		printf("Title�V�[��\n");

		break;
	case 1:
		printf("SceneNo:1\n");
		printf("NewGame�V�[��\n");

		break;
	case 2:
		printf("SceneNo:2\n");
		printf("GamePlay�V�[��\n");

		break;
	case 3:
		printf("SceneNo:3\n");
		printf("GameClear�V�[��\n");

		break;
	default:
		break;
	}
}