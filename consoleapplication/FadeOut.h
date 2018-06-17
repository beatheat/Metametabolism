#ifndef _FADEOUT_H_
#define _FADEOUT_H_

#include"Diesel.h"

class FadeOut : public Object
{
public:
	Texture *tColor;
	int count;
public:
	void Initialize() override;
	void Step() override;
	void Draw() override;
	void Release() override;
};

#endif