#include"Scene.h"

#include"System.h"
#include"Camera.h"

void Scene::Clear()
{
	SDL_SetRenderDrawColor(GetSystem.renderer, 208,74,64, 255);
	SDL_RenderClear(GetSystem.renderer);
	SDL_SetRenderDrawColor(GetSystem.renderer, 255, 255, 255, 255);
}

void Scene::Pause()
{
	isPause = true;
}

void Scene::Resume()
{
	isPause = false;
}

void Scene::Reset()
{
	ReleaseScene();
	Initialize();
}


int Scene::CreateObjectWithTag(Object* object, double x, double y, double direction, double speed, const std::string &tag)
{
	object->parent = this;
	object->id = assignObjectId++;
	object->x = x;
	object->y = y;
	object->direction = direction;
	object->speed = speed;
	object->tag = tag;
	object->Initialize();

	objectMap.insert(std::make_pair(object->id, object));

	return object->id;
}

int Scene::CreateObjectWithTag(Object* object, double x, double y, const std::string &tag)
{
	return CreateObjectWithTag(object, x, y, 0, 0, tag);
}

int Scene::CreateObjectWithTag(Object* object, const std::string &tag)
{
	return CreateObjectWithTag(object, 0, 0, tag);
}

int Scene::CreateObject(Object* object, double x, double y, double direction, double speed)
{
	return CreateObjectWithTag(object, x, y, direction, speed, "-98012");
}

int Scene::CreateObject(Object* object, double x, double y)
{
	return CreateObject(object, x, y, 0, 0);
}

int Scene::CreateObject(Object* object)
{
	return CreateObject(object, 0, 0);
}

void Scene::CreateTimeline(Timeline *timeline)
{
	timeline->parent = this;
	timelines.insert(std::make_pair(assignTimelineId++, timeline));
}

void Scene::Background()
{
	SDL_GetMouseState(&mouse.x, &mouse.y);
	GetCamera.Update();

	SDL_SetRenderTarget(GetSystem.renderer, GetSystem.buffer);
	Clear();

	TimelineMap::iterator timEnd = timelines.end();
	for (timIter = timelines.begin(); timIter != timEnd;)
	{
		(*timIter).second->Background();
	}

	ObjectMap::iterator objEnd = objectMap.end();
	for (objectIterator = objectMap.begin(); objectIterator != objEnd;)
	{
		(*objectIterator).second->Background();
	}

	SDL_SetRenderTarget(GetSystem.renderer, NULL);
	Clear();
	SDL_RenderCopyEx(GetSystem.renderer, GetSystem.buffer, &GetCamera.src, &GetCamera.dst, GetCamera.angle, &GetCamera.center, SDL_FLIP_NONE);

	SDL_RenderPresent(GetSystem.renderer);
}

void Scene::ReleaseScene()
{
	Release();
	ObjectMap::iterator objectEnd = objectMap.end();
	for (objectIterator = objectMap.begin(); objectIterator != objectEnd;)
	{
		objectMap.erase(objectIterator++);
	}
	

	ColliderMap::iterator colliderIterator;
	ColliderMap::iterator colliderEnd = colliderMap.end();
	for (colliderIterator = colliderMap.begin(); colliderIterator != colliderEnd;)
	{
		colliderMap.erase(colliderIterator++);
	}

	ClickableMap::iterator clickableIterator;
	ClickableMap::iterator clickableEnd = clickableMap.end();
	for (clickableIterator = clickableMap.begin(); clickableIterator != clickableEnd;)
	{
		clickableMap.erase(clickableIterator++);
	}
}