#include "Timer.h"

#include "Frame.h"

Timer *Timer::Create()
{
	auto timer = new Timer();

	return timer;
}

bool Timer::Tick(int interval)
{
	if (!isFirst) {
		startTick = GetFrame.tick;
		isFirst = true;
	}
	if (GetFrame.tick - startTick >= interval) {
		startTick = GetFrame.tick;
		return true;
	}
	return false;
}

void Timer::Reset()
{
	startTick = GetFrame.tick;
}

void Timer::Release()
{
	delete this;
}
