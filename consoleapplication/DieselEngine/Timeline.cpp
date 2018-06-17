#include "Timeline.h"

#include "System.h"
#include "Scene.h"

void Timeline::Background()
{
	tick += 1;

	if (isDestroy) {
		parent->timelines.erase(parent->timIter++);
		return;
	}
	else
		++parent->timIter;

	if (!parent->isPause && GetSystem.isWindowActivate)
	{
		Step();
	}
}

void Timeline::End()
{
	isDestroy = true;
}
