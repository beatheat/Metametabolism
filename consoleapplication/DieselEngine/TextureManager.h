#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include<SDL.h>

#define GetTextureManager TextureManager::GetInstance()

typedef enum _TextureAccess{
	TEXTUREACCESS_STATIC, TEXTUREACCESS_STREAMING, TEXTUREACCESS_TARGET
}TextureAccess;

class Texture;
class TextureManager
{
public:
	static TextureManager *tm;

public:
	Texture *CreateTexture(int width,int height,TextureAccess access);
	Texture* SetRenderTarget(Texture *texture);
public:
	static TextureManager &GetInstance();
	void Release();
};

#endif