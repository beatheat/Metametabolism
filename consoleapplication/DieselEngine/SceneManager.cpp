#include "SceneManager.h"

SceneManager *SceneManager::sm = 0;

SceneManager &SceneManager::GetInstance()
{
	if (sm == 0) sm = new SceneManager();
	return *sm;
}

void SceneManager::Release()
{
	currentScene->ReleaseScene();
	delete currentScene;
	delete this;
}

void SceneManager::ReplaceScene(const std::string &tag)
{
	currentScene->ReleaseScene();
	currentScene = sceneMap[tag];
	currentScene->Initialize();
}