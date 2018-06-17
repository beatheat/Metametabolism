#include"TextureManager.h"

#include"ResourceManager.h"

TextureManager *TextureManager::tm = 0;

TextureManager &TextureManager::GetInstance()
{
	if (tm == NULL){
		tm = new TextureManager;
	}
	return *tm;
}

Texture* TextureManager::CreateTexture(int width,int height,TextureAccess access)
{
	Texture *texture = new Texture;
	texture->texture = SDL_CreateTexture(GetSystem.renderer, SDL_GetWindowPixelFormat(GetSystem.window), (SDL_TextureAccess)access, width, height);
	texture->Init(0, 1, 1, 1, 0.5, 0.5, 0, BLENDMODE_BLEND);
	return texture;
}

Texture* TextureManager::SetRenderTarget(Texture *texture)
{
	if (texture == NULL) 
		SDL_SetRenderTarget(GetSystem.renderer, GetSystem.buffer);
	else 
		SDL_SetRenderTarget(GetSystem.renderer, texture->texture);
	return texture;
}

void TextureManager::Release()
{
	delete this;
	return;
}

