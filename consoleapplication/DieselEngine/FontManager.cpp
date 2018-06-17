#include"FontManager.h"

#include"ResourceManager.h"

FontManager *FontManager::fm = 0;

FontManager &FontManager::GetInstance()
{
	if (fm == 0) fm = new FontManager;
	return *fm;
}

TTF_Font *FontManager::GetFont(const std::string &name, int size)
{
	if (GetResourceManager.fontMap[name].size() == 0){
		printf("Error: no font file\n");
		return 0;
	}
	TTF_Font *font = TTF_OpenFont(GetResourceManager.fontMap[name].c_str() , size);
	return font;
}

void FontManager::Release()
{
	delete this;
}