#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#define GetSceneManager SceneManager::GetInstance()

#include "Scene.h"

#include <map>
#include <string>

class SceneManager
{
private:
	SceneManager(){};

private:
	static SceneManager *sm;

public:
	std::map<std::string, Scene *> sceneMap;

	Scene *currentScene;

public:
	static SceneManager &GetInstance();

	void Release();

	void ReplaceScene(const std::string &tag);

};

#endif