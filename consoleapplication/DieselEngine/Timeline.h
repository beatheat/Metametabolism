#ifndef _TIMELINE_H_
#define _TIMELINE_H_

#include<map>

class Scene;

class Timeline
{
public:
	Scene *parent;
	int tick;
	int id;

	bool isDestroy = false;

public:
	virtual void Step() = 0;

public:
	void Background();
	void End();

};

typedef std::map<int, Timeline *> TimelineMap;

#endif