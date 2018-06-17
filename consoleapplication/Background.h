#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include"Diesel.h"

#define FORENUM 4
#define BACKNUM 2

class Back : public Object
{
public:
	int fsituation;
	int bsituation;

	Texture *foreground[FORENUM];
	Texture *background[BACKNUM];

	Texture *tSofa;
	Texture *tBed;

	Texture *tBus;
	Texture *tDarkhill;

	Texture *tSubway;
	Texture *tFlow;

	Timer *timer;
	Random random;

	double shake_x, shake_y;
	int count_shake;
public:
	void Initialize() override;
	void Step() override;
	void Draw() override;
	void Release() override;
};

#endif