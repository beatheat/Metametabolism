#include "KeyboardEvent.h"

#include "KeyboardInput.h"

#include "Timer.h"
#include "Scene.h"

KeyboardEvent *KeyboardEvent::Create()
{
	auto ke = new KeyboardEvent;
	ke->flag = false;

	ke->timer = Timer::Create();

	return ke;
}

bool KeyboardEvent::GetKeyPressed(unsigned char keycode)
{
	if (GetKeyboard.Check(keycode) && !flag) {
		flag = true;
		return true;
	}

	if (GetKeyboard.ReleaseCheck(keycode)) {
		flag = false;
	}

	return false;
}

bool KeyboardEvent::GetKeyDelay(unsigned char keycode, unsigned int fDelay, unsigned int mDelay)
{
	/// 키 처음 눌렀을때
	if (GetKeyboard.Check(keycode) && !firstFlag) {
		tickOn = true;
		firstFlag = true;
		return true;
	}

	if (GetKeyboard.ReleaseCheck(keycode)) {
		tickOn = false;
		moveOn = false;
		firstFlag = false;
		tick = 0;
	}

	if (tickOn) {
		tick += 1;
		if (tick >= fDelay) {
			moveOn = true;
		}
	}

	if (moveOn) {
		if (timer->Tick(mDelay))
			return true;
		return false;
	}

	return false;
}

bool KeyboardEvent::GetKeyReleased(unsigned char keycode)
{
	if (GetKeyboard.ReleaseCheck(keycode) && !rflag) {
		rflag = true;
		return true;
	}

	if (GetKeyboard.Check(keycode)) {
		rflag = false;
	}

	return false;
}

void KeyboardEvent::Release()
{
	timer->Release();
	delete this;
}