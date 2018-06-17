#ifndef _OBJECT_H_
#define _OBJECT_H_

#include<string>
#include<map>
#include"ResourceManager.h"

using namespace std;

class Scene;
class Collider;

class Object
{
public:
	double x = 0, y = 0;
	double previousX = 0, previousY = 0;
	double scaleX = 1, scaleY = 1;
	double angle = 0;

	double speed = 0;
	double direction = 0;

	int r = 255, g = 255, b = 255;
	int id;

	bool isRelease = false;

	string tag = "-970521";

	Scene *parent;

public:
	void Background();
	void ReleaseObject();

public:
	void DrawTexturePart(Texture *texture, double x, double y, int left, int top, int width, int height, int r, int g, int b);
	void DrawTexturePart(Texture *texture, double x, double y, int left, int top, int width, int height);

	void DrawTexture(Texture *texture, double x, double y, int r, int g, int b);
	void DrawTexture(Texture *texture, double x, double y);
	void DrawTexture(Texture *texture);

	void DrawLine(double x1, double y1, double x2, double y2);

	int DrawNumber(Texture *texture, int number, int space, double x, double y, int align);

public:
	Collider *GetCollider(int id);

public:
	virtual void Initialize() = 0;
	virtual void Step() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
};

typedef map<int, Object*> ObjectMap;

#endif