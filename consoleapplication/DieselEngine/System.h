#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2_image")
#pragma comment(lib,"SDL2_mixer")
#pragma comment(lib,"SDL2_ttf")

#undef main
	
#define GetSystem System::GetInstance()

class System
{
private:
	System() : isWindowActivate(true), exit(false) {};
private:
	static System    *system;

public:
	SDL_Window       *window;
	SDL_Renderer     *renderer;
	SDL_Texture      *buffer;
	SDL_Event        event;

	bool             isWindowActivate;
	bool             exit;

	int              width;
	int            	 height;
public:
	static System &GetInstance();
	void Release();

public:
	void Exit();
};

#endif 