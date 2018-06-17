#ifndef _MOUSEEVENT_H_
#define _MOUSEEVENT_H_

#include "MouseInput.h"

class MouseEvent
{
private:
	bool isClick = false;

public:
	bool MouseDown(MouseCode code);
	bool MouseClick(MouseCode code);
	bool MouseRelease(MouseCode code);

	void Release();
};

#endif