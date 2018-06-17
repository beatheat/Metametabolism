#include"Engine.h"

#include<SDL.h>

#include"Frame.h"
#include"System.h"
#include"SceneManager.h"
#include"Math.h"
#include"Camera.h"
#include"MouseInput.h"
#include"KeyboardInput.h"
#include"Function.h"
#include"AudioEngine.h"
#include"FontManager.h"
#include"TextureManager.h"
#include"KeyCode.h"


Engine::Engine(const char *title, int width, int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	GetSystem.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	GetSystem.renderer = SDL_CreateRenderer(GetSystem.window, -1, SDL_RENDERER_ACCELERATED);
	GetSystem.buffer = SDL_CreateTexture(GetSystem.renderer, SDL_GetWindowPixelFormat(GetSystem.window) , SDL_TEXTUREACCESS_TARGET, width, height);

	//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	setlocale(LC_ALL, "");
	TTF_Init();
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);

	GetSystem.width = width;
	GetSystem.height = height;

	GetMath.CreateTable();
	GetCamera.Update();
	GetFrame;
	GetMouse;
	GetKeyboard;
	GetFn;
	GetResourceManager;
	GetSceneManager;
	GetAudio;
	GetFontManager;
	GetTextureManager;
}

void Engine::Release()
{
	GetMath.Release();
	GetCamera.Release();
	GetFrame.Release();
	GetMouse.Release();
	GetKeyboard.Release();
	GetFn.Release();
	GetResourceManager.Release();
	GetSceneManager.Release();
	GetAudio.Release();
	GetFontManager.Release();
	GetTextureManager.Release();

	GetSystem.Release();

	SDL_Quit();
	TTF_Quit();
	Mix_CloseAudio();
}

bool full = false;

int Engine::Run()
{

	int fpsCalcCount = 0;
	unsigned long fpsCalcTick = SDL_GetTicks();

	GetSceneManager.currentScene->Initialize();

	while (!GetSystem.exit)
	{
		GetFrame.nowTick = SDL_GetTicks();
		if (GetFrame.oldTick == 0) GetFrame.oldTick = GetFrame.nowTick;

		if (GetFrame.nowTick >= GetFrame.oldTick + 1000.0 / GetFrame.speed)
		{
			fpsCalcCount += 1;

			GetKeyboard.Read();
			if (SDL_PollEvent(&GetSystem.event))
			{
				if (GetSystem.event.type == SDL_QUIT)
					GetSystem.exit = true;
				if (GetSystem.event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (GetSystem.event.button.button == SDL_BUTTON_LEFT) GetMouse.left = true;
					if (GetSystem.event.button.button == SDL_BUTTON_RIGHT) GetMouse.right = true;
					if (GetSystem.event.button.button == SDL_BUTTON_MIDDLE) GetMouse.middle = true;

				}
				if (GetSystem.event.type == SDL_MOUSEBUTTONUP)
				{
					if (GetSystem.event.button.button == SDL_BUTTON_LEFT) GetMouse.left = false;
					if (GetSystem.event.button.button == SDL_BUTTON_RIGHT) GetMouse.right = false;
					if (GetSystem.event.button.button == SDL_BUTTON_MIDDLE) GetMouse.middle = false;
				}
				if (GetSystem.event.type == SDL_MOUSEWHEEL)
				{
					//
				}
				if (GetSystem.event.type == SDL_WINDOWEVENT)
				{
					if (GetSystem.event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
						GetSystem.isWindowActivate = true;
					if (GetSystem.event.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
						GetSystem.isWindowActivate = false;
				}
				if (GetSystem.event.type == SDL_KEYDOWN)
				{
					if (GetSystem.event.key.keysym.sym == SDLK_F10)
					{
						if (!full){
							full = true;
							SDL_SetWindowFullscreen(GetSystem.window, SDL_WINDOW_FULLSCREEN);
						}
						else{
							full = false;
							SDL_SetWindowFullscreen(GetSystem.window, 0);
						}
					}
				}
			}

			GetSceneManager.currentScene->Background();

			GetFrame.oldTick += 1000.0 / GetFrame.speed;

			if (fpsCalcCount >= 10)
			{
				GetFrame.fps = 1000.0 * fpsCalcCount / (GetFrame.nowTick - fpsCalcTick);
				fpsCalcTick = GetFrame.nowTick;
				fpsCalcCount = 0;
			}
			if (!GetSceneManager.currentScene->isPause || !GetSystem.isWindowActivate)
				GetFrame.tick += 1;
		}
	}
	return 0;
}