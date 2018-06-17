#ifndef _SCENE_H_
#define _SCENE_H_

#include<SDL.h>

#include"Object.h"
#include"Collider.h"
#include"Clickable.h"
#include"Timeline.h"

class Scene
{
public:
	bool                isPause = false;
	bool                isRelease = false;
	int                 assignObjectId = 0;
	int                 assignColliderId = 0;
	int                 assignClickableId = 0;
	int                 assignTimelineId = 0;
			            
	int                 sceneWidth, sceneHeight;
	SDL_Point           mouse;
			        
	ObjectMap           objectMap;
	ObjectMap::iterator objectIterator;

	ColliderMap         colliderMap;
	ClickableMap        clickableMap;

	TimelineMap timelines;
	TimelineMap::iterator timIter;
public:
	virtual void Initialize() = 0;
	virtual void Release() = 0;

public:
	void Pause();
	void Resume();

	void Reset();

	void Clear();

	int CreateObjectWithTag(Object* object, double x, double y, double direction, double speed, const std::string &tag);
	int CreateObjectWithTag(Object* object, double x, double y, const std::string &tag);
	int CreateObjectWithTag(Object* object, const std::string &tag);

	int CreateObject(Object* object, double x, double y, double direction, double speed);
	int CreateObject(Object* object, double x, double y);
	int CreateObject(Object* object);

	void CreateTimeline(Timeline *timeline);
public:
	void Background();
	void ReleaseScene();
};

#endif