#ifndef _GRAPH_H_
#define _GRAPH_H_

#include"Diesel.h"
#include<list>
#include<string>

typedef struct Line{
	double nx, ny;
	double ex, ey;
}Line;

class Graph : public Object
{
public:
	Texture *tBox;
	std::list<Line> lines;
public:
	void Initialize() override;
	void Step() override;
	void Draw() override;
	void Release() override;
};

#endif