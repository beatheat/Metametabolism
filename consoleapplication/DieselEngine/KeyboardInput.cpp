#include"KeyboardInput.h"

KeyboardInput *KeyboardInput::ki = 0;

KeyboardInput &KeyboardInput::GetInstance()
{
	if (ki == 0) ki = new KeyboardInput();
	return *ki;
}

void KeyboardInput::Read()
{
	keyState = SDL_GetKeyboardState(NULL);
}

bool KeyboardInput::Check(unsigned char keycode)
{
	if (keyState[keycode])
		return true;
	return false;
}

bool KeyboardInput::ReleaseCheck(unsigned char keycode)
{
	if (!keyState[keycode])
		return true;
	return false;
}

void KeyboardInput::Release()
{
	SDL_free(&keyState);
	delete this;
}