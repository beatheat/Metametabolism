#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <string>

#include "Scene.h"

class Resource
{
public:


public:
	void AddScene(Scene *firstScene, ...);

	void CreateMap(const std::string &srcPath, const std::string &dstPath, const std::string &dstFileName);
	void CreateMap(const std::string &srcPath, const std::string &dstPath, const std::string &dstFileName, const std::string &extension);

	void LoadTextureMap(const char *path);
	void LoadSEMap(const char *path);
	void LoadBGMMap(const char *path);
	void LoadFontMap(const char *path);
};

#endif