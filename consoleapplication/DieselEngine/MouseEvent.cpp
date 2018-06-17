#include "MouseEvent.h"

bool MouseEvent::MouseDown(MouseCode code)
{
	if (GetMouse.Check(code))
		return true;
	return false;
}

bool MouseEvent::MouseClick(MouseCode code)
{
	if (GetMouse.Check(code)) {
		if (!isClick) {
			isClick = true;
			return true;
		}
	}
	if (GetMouse.ReleaseCheck(code)) {
		isClick = false;
	}
	return false;
}

bool MouseEvent::MouseRelease(MouseCode code)
{
	if (GetMouse.ReleaseCheck(code)) {
		if (isClick) {
			isClick = false;
			return true;
		}
	}
	if (GetMouse.ReleaseCheck(code)) {
		isClick = true;
	}
	return false;
}

void MouseEvent::Release()
{
	delete this;
}
