#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include<SDL.h>
#include<SDL_ttf.h>
#include<string>
#include<map>

#include"SE.h"
#include"BGM.h"
#include"System.h"

using namespace std;

#define GetResourceManager ResourceManager::GetInstance()

typedef enum _BlendMode{
	BLENDMODE_NONE = 0, BLENDMODE_BLEND = 1, BLENDMODE_ADD = 2, BLENDMODE_MOD = 3
}BlendMode;

typedef struct _Color{
	int a, r, g, b;
}Color;

class Texture
{
public:
	SDL_Texture *texture;
	BlendMode blendmode;
	int width, height;
	double angle;
	double alpha;
	double scaleX, scaleY;
	double centerX, centerY;
	double z;

public:
	inline void Init(double angle, double alpha, double scaleX, double scaleY, double centerX, double centerY, double z, BlendMode blendmode)
	{this->angle = angle; this->alpha = alpha; this->scaleX = scaleX; this->scaleY = scaleY; this->centerX = centerX; this->centerY = centerY; this->z = z; this->blendmode = blendmode;};
	inline void SetScale(double scaleX, double scaleY){ this->scaleX = scaleX; this->scaleY = scaleY; };
	inline void SetCenter(double centerX, double centerY){ this->centerX = centerX; this->centerY = centerY; };
};

typedef map<string, SDL_Texture*> TextureMap;
typedef map<string, SE*> SEMap;
typedef map<string, BGM*> BGMMap;
typedef map<string, string> FontMap;

class ResourceManager
{
private:
	ResourceManager(){};
private:
	static ResourceManager *rm;

private:
	TextureMap             textureMap;

public:
	SEMap                  seMap;
	BGMMap                 bgmMap;
	FontMap                fontMap;
public:
	static ResourceManager &GetInstance();

	void Release();

	int LoadTextureMap(const char *path);
	int LoadSEMap(const char *path);
	int LoadBGMMap(const char*path);
	int LoadFontMap(const char*path);

public:
	Texture *GetTexture(const std::string &tag);
};

#endif 