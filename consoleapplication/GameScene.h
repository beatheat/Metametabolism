#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include"Diesel.h"

#include"Human.h"
#include"UI.h"
#include"Background.h"
#include"FadeIn.h"

class GameScene : public Scene
{
public:
	void Initialize()
	{
		CreateObject(new Back);
		CreateObject(new Human);
		CreateObject(new UI);
		CreateObject(new FadeIn);
	}

	void Release()
	{

	}
};

#endif