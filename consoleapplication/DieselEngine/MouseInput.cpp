#include "MouseInput.h"

MouseInput *MouseInput::mi = 0;

MouseInput &MouseInput::GetInstance()
{
	if (mi == 0) mi = new MouseInput();
	return *mi;
}


bool MouseInput::Check(MouseCode keycode)
{
	switch (keycode)
	{
	case MOUSE_LEFT: return left;
	case MOUSE_RIGHT: return right;
	case MOUSE_WHEEL: return middle;
	}
	return false;
}

bool MouseInput::ReleaseCheck(MouseCode keycode)
{
	switch (keycode)
	{	
	case MOUSE_LEFT: return !left;
	case MOUSE_RIGHT: return !right;
	case MOUSE_WHEEL: return !middle;
	}
	return false;
}

void MouseInput::Release()
{
	delete this;
}