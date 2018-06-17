#ifndef _CLICKABLE_H_
#define _CLICKABLE_H_

#include <SDL.h>
#include <map>
#include <string>
#include <functional>
#include "Collider.h"
#include "MouseEvent.h"

class Object;

class Clickable
{
public:
	Object *parent;

	double x, y;
	int width, height;
	int diameter;

	int id;

	bool enable = true;
	bool isClickableRelease = false;
	bool isClicked = false;

	bool isClick = false;
	bool isRelease = false;

	BoundingType type;
	MouseEvent *mouseClick;
	MouseEvent *mouseRelease;

public:
	static Clickable *CreateRectangle(Object *parent, float x, float y, int width, int height);
	static Clickable *CreateCircle(Object *parent, float x, float y, int diameter);

	void SetPosition(float x, float y);

	bool IsClicked(const SDL_Point &mouse);
	bool IsReleased(const SDL_Point &mouse);

	bool IsOn(const SDL_Point &mouse);

	bool IsClicked();
	bool IsReleased();

	void Release();

};

typedef std::map<int, Clickable *> ClickableMap;

#endif