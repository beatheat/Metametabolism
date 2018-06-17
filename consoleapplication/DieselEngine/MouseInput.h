#ifndef _MOUSEINPUT_H_
#define _MOUSEINPUT_H_

#define GetMouse MouseInput::GetInstance()

#include<SDL.h>

typedef enum MouseCode {
	MOUSE_LEFT, MOUSE_RIGHT, MOUSE_WHEEL
}MouseCode;

class MouseInput
{
private:
	MouseInput() : left(false),right(false),middle(false) {};

private:
	static MouseInput *mi;

public:
	bool              left;
	bool              right;
	bool              middle;

public:
	static MouseInput &GetInstance();
	void Release();

public:
	bool Check(MouseCode keycode);
	bool ReleaseCheck(MouseCode keycode);
};

#endif