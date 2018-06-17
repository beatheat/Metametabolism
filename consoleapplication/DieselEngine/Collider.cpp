#include "Collider.h"

#include "Object.h"
#include "Function.h"
#include "Scene.h"

Collider *Collider::CreateRectangle(Object *parent, double x, double y, int width, int height)
{
	auto collider = new Collider;

	collider->parent = parent;
	collider->type = RECTANGLE;
	collider->x = x;
	collider->y = y;
	collider->width = width;
	collider->height = height;

	collider->id = parent->parent->assignColliderId++;
	parent->parent->colliderMap.insert(std::make_pair(collider->id, collider));

	return collider;
}

Collider *Collider::CreateCircle(Object *parent, double x, double y, int diameter)
{
	auto collider = new Collider;

	collider->parent = parent;
	collider->type = CIRCLE;
	collider->x = x;
	collider->y = y;
	collider->diameter = diameter;

	collider->id = parent->parent->assignColliderId++;
	parent->parent->colliderMap.insert(std::make_pair(collider->id, collider));

	return collider;
}


void Collider::CollisionCheck(const std::function<void(int id)> &function)
{
	ColliderMap::iterator iterator;
	ColliderMap::iterator end = parent->parent->colliderMap.end();
	for (iterator = parent->parent->colliderMap.begin(); iterator != end;)
	{
		if ((*iterator).second == this || !(*iterator).second->enable) {
			if ((*iterator).second->isRelease)
				parent->parent->colliderMap.erase(iterator++);
			else
				iterator++;

			continue;
		}

		if ((*iterator).second->type == RECTANGLE) {
			if (CollisionToRectangle((*iterator).second)) {
				function((*iterator).second->id);
			}
		}
		else if ((*iterator).second->type == CIRCLE) {
			if (CollisionToCircle((*iterator).second)) {
				function((*iterator).second->id);
			}
		}

		if ((*iterator).second->isRelease)
			parent->parent->colliderMap.erase(iterator++);
		else
			iterator++;

	}
}

void Collider::CollisionCheckWithTag(const std::string &tag, const std::function<void(int id)> &function)
{
	ColliderMap::iterator iterator;
	ColliderMap::iterator end = parent->parent->colliderMap.end();
	for (iterator = parent->parent->colliderMap.begin(); iterator != end;)
	{
		if ((*iterator).second == this || !(*iterator).second->enable || (*iterator).second->parent->tag != tag) {
			if ((*iterator).second->isRelease)
				parent->parent->colliderMap.erase(iterator++);
			else
				iterator++;

			continue;
		}

		if ((*iterator).second->type == RECTANGLE) {
			if (CollisionToRectangle((*iterator).second)) {
				function((*iterator).second->id);
			}
		}
		else if ((*iterator).second->type == CIRCLE) {
			if (CollisionToCircle((*iterator).second)) {
				function((*iterator).second->id);
			}
		}

		if ((*iterator).second->isRelease)
			parent->parent->colliderMap.erase(iterator++);
		else
			iterator++;

	}
}

void Collider::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Collider::Release()
{
	isRelease = true;
}

bool Collider::CollisionToRectangle(Collider *other)
{
	if (type == RECTANGLE) {
		if (GetFn.CollisionRectToRect(this->x, this->y, this->width, this->height, other->x, other->y, other->width, other->height))
			return true;
		return false;
	}
	else if (type == CIRCLE) {
		if (GetFn.CollisionRectToCircle(other->x, other->y, other->width, other->height, this->x, this->y, this->diameter))
			return true;
		return false;
	}
}

bool Collider::CollisionToCircle(Collider *other)
{
	if (type == RECTANGLE) {
		if (GetFn.CollisionRectToCircle(this->x, this->y, this->width, this->height, other->x, other->y, other->diameter))
			return true;
		return false;
	}
	else if (type == CIRCLE) {
		if (GetFn.CollisionCircleToCircle(this->x, this->y, this->diameter, other->x, other->y, other->diameter))
			return true;
		return false;
	}
}