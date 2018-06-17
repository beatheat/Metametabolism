#ifndef _KEYBOARDINPUT_H_
#define _KEYBOARDINPUT_H_

#include<SDL.h>

#define GetKeyboard KeyboardInput::GetInstance()

class KeyboardInput
{
private:
	KeyboardInput(){};

private:
	static KeyboardInput *ki;

public:
	const Uint8          *keyState;
	
public:
	static KeyboardInput &GetInstance();
	void Release();

public:
	void Read();

public:
	bool Check(unsigned char keycode);
	bool ReleaseCheck(unsigned char keycode);
};

#endif