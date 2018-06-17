#ifndef _FONTMANAGER_H_
#define _FONTMANAGER_H_

#include<string>
#include<SDL_ttf.h>
#include<vector>

#define GetFontManager FontManager::GetInstance()

class FontManager
{
private:
	static FontManager *fm;
public:
	static FontManager &GetInstance();
	void Release();
public:
	static TTF_Font *GetFont(const std::string &name,int size);
};

#endif