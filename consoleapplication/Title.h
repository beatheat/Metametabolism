#ifndef _TITLE_H_
#define _TITLE_H_

#include"Diesel.h"
#include<vector>

typedef struct _Hemo
{
	Texture *texture;
	double x, y;
	double speed_x,speed_y;
	double speed_angle;
}Hemo;

class Title : public Object
{
public:
	Texture *tTitle;
	Texture *tStart[2];
	Texture *tExit[2];

	std::vector<Hemo*> tHemo;
	std::vector<Hemo*> tHemo2;
	Timer *timer;

	int count;

	Random random;

	Clickable *cStart;
	Clickable *cExit;

	int start, exit;
	double dx;
	bool first;
public:
	void Initialize() override;
	void Step() override;
	void Draw() override;
	void Release() override;
};

#endif 