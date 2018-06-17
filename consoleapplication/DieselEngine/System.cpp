#include"System.h"


System *System::system;

System &System::GetInstance()
{
	if (system == NULL)system = new System();
	return *system;
}

void System::Release()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(buffer);
	delete this;
}

void System::Exit()
{
	exit = true;
}