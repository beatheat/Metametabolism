#include "Clickable.h"

#include "Object.h"
#include "Scene.h"
#include "Function.h"

Clickable *Clickable::CreateRectangle(Object *parent, float x, float y, int width, int height)
{
	auto clickable = new Clickable;

	clickable->parent = parent;
	clickable->type = RECTANGLE;
	clickable->x = x;
	clickable->y = y;
	clickable->width = width;
	clickable->height = height;
	clickable->mouseClick = new MouseEvent;
	clickable->mouseRelease = new MouseEvent;

	parent->parent->clickableMap.insert(std::make_pair(parent->parent->assignClickableId++, clickable));

	return clickable;
}

Clickable *Clickable::CreateCircle(Object *parent, float x, float y, int diameter)
{
	auto clickable = new Clickable;

	clickable->parent = parent;
	clickable->type = CIRCLE;
	clickable->x = x;
	clickable->y = y;
	clickable->diameter = diameter;
	clickable->mouseClick = new MouseEvent;
	clickable->mouseRelease = new MouseEvent;

	parent->parent->clickableMap.insert(std::make_pair(parent->parent->assignClickableId++, clickable));

	return clickable;
}

void Clickable::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

bool Clickable::IsClicked(const SDL_Point &mouse)
{
	isClick = false;
	if (type == RECTANGLE) {
		if (!isClicked && mouseClick->MouseClick(MOUSE_LEFT)) {
			if (GetFn.CollisionPointToRect(mouse.x, mouse.y, x, y, width, height)){
				isClicked = true;
				isClick = true;
				return true;
			}
		}
	}
	else if (type == CIRCLE) {
		if (!isClicked && mouseClick->MouseClick(MOUSE_LEFT)) {
			if (GetFn.CollisionPointToCircle(mouse.x, mouse.y, x, y, diameter)){
				isClicked = true;
				isClick = true;
				return true;
			}
		}
	}

	isRelease = false;
	if (type == RECTANGLE) {
		if (isClicked && mouseRelease->MouseRelease(MOUSE_LEFT)) {
			isClicked = false;
			if (GetFn.CollisionPointToRect(mouse.x, mouse.y, x, y, width, height)){
				isRelease = true;
			}
		}
	}
	else if (type == CIRCLE) {
		if (isClicked && mouseRelease->MouseRelease(MOUSE_LEFT)) {
			isClicked = false;
			if (GetFn.CollisionPointToCircle(mouse.x, mouse.y, x, y, diameter)){
				isRelease = true;
			}
		}
	}
	return false;
}

bool Clickable::IsReleased(const SDL_Point &mouse)
{
	isClick = false;
	if (type == RECTANGLE) {
		if (!isClicked && mouseClick->MouseClick(MOUSE_LEFT)) {
			if (GetFn.CollisionPointToRect(mouse.x, mouse.y, x, y, width, height)) {
				isClicked = true;
				isClick = true;
			}
		}
	}
	else if (type == CIRCLE) {
		if (!isClicked && mouseClick->MouseClick(MOUSE_LEFT)) {
			if (GetFn.CollisionPointToCircle(mouse.x, mouse.y, x, y, diameter)) {
				isClicked = true;
				isClick = true;
			}
		}
	}

	isRelease = false;

	if (type == RECTANGLE) {
		if (isClicked && mouseRelease->MouseRelease(MOUSE_LEFT)) {
			isClicked = false;
			if (GetFn.CollisionPointToRect(mouse.x, mouse.y, x, y, width, height)) {
				isRelease = true;
				return true;
			}
		}
	}
	else if (type == CIRCLE) {
		if (isClicked && mouseRelease->MouseRelease(MOUSE_LEFT)) {
			isClicked = false;
			if (GetFn.CollisionPointToCircle(mouse.x, mouse.y, x, y, diameter)) {
				isRelease = true;
				return true;
			}
		}
	}
	return false;
}

bool Clickable::IsOn(const SDL_Point &mouse)
{
	if (type == RECTANGLE) {
		if (GetFn.CollisionPointToRect(mouse.x, mouse.y, x, y, width, height)) {
			return true;
		}
	}
	else if (type == CIRCLE) {
		if (GetFn.CollisionPointToCircle(mouse.x, mouse.y, x, y, diameter)) {
			return true;
		}
	}
	return false;
}

bool Clickable::IsClicked()
{
	if (isClick)
		return true;
	return false;
}

bool Clickable::IsReleased()
{
	if (isRelease)
		return true;
	return false;
}

void Clickable::Release()
{
	isClickableRelease = true;
	mouseClick->Release();
	mouseRelease->Release();
	parent->parent->clickableMap.erase(id);
}