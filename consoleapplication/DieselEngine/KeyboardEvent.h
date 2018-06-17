#pragma once

#include "Timer.h"

class KeyboardEvent
{
private:
	bool flag = false;
	bool rflag = false;

	Timer *timer;
	int tick = 0;

	bool firstFlag = false;
	bool tickOn = false;
	bool moveOn = false;

public:
	static KeyboardEvent *Create();

	bool GetKeyPressed(unsigned char keycode);

	bool GetKeyDelay(unsigned char keycode, unsigned int fDelay, unsigned int mDelay);

	bool GetKeyReleased(unsigned char keycode);

	void Release();

};