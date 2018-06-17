#ifndef _COLLIDER_H_
#define _COLLIDER_H_

#include <map>
#include <string>
#include <functional>

class Object;

enum BoundingType{
	RECTANGLE, CIRCLE
};

class Collider
{
public:
	Object *parent;

	double x, y;
	int width, height;
	int diameter;

	int id;

	bool enable = true;
	bool isRelease = false;

	BoundingType type;

public:
	static Collider *CreateRectangle(Object *parent, double x, double y, int width, int height);
	static Collider *CreateCircle(Object *parent, double x, double y, int diameter);

	/*매개변수 id는 충돌한 상대 collider의 id*/
	void CollisionCheck(const std::function<void(int id)> &function);
	void CollisionCheckWithTag(const std::string &tag, const std::function<void(int id)> &function);

	void SetPosition(float x, float y);

	void Release();

public:
	bool CollisionToRectangle(Collider *other);
	bool CollisionToCircle(Collider *other);


};

typedef std::map<int, Collider *> ColliderMap;

#endif