#ifndef _UI_H_
#define _UI_H_

#include"Diesel.h"
#include<list>

class UI : public Object
{
public:
	Texture *tUI;
	Label *lOxygen;
	Label *lHeart;
	Label *lSugar;
	Label *lPressure;
	Label *lCholesterol;

	Texture *tMsgbox;
	Texture *tMsgbox2;
	Texture *tMsgbox3;
	Label *msglist[11];
	Label *msglist2[21];
	Label *msglist3[3];
	KeyboardEvent *keyevent;
public:
	void Initialize() override;
	void Step() override;
	void Draw() override;
	void Release() override;
};

#endif