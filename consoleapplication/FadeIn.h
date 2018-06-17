#ifndef _FADEIN_H_
#define _FADEIN_H_

#include"Diesel.h"

class FadeIn : public Object
{
public:
	Texture *tColor;
public:
	void Initialize() override;
	void Step() override;
	void Draw() override;
	void Release() override;
};

#endif