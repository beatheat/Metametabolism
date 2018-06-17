#include "Resource.h"

#include "ResourceManager.h"
#include "SceneManager.h"
#include "System.h"
#include "Function.h"

#include <fstream>
#include <io.h>
#include <stdarg.h>

using namespace std;

void Resource::AddScene(Scene* firstScene, ...)
{
	va_list args;

	va_start(args, firstScene);

	std::string className = typeid(*firstScene).name();
	std::string tag = GetFn.StringSplit(className, " ")[1];

	GetSceneManager.sceneMap.insert(std::make_pair(tag, firstScene));
	GetSceneManager.currentScene = (*GetSceneManager.sceneMap.begin()).second;

	Scene* i = va_arg(args, Scene*);
	printf("%s\n", tag.c_str());

	while (i)
	{
		className = typeid(*i).name();
		tag = GetFn.StringSplit(className, " ")[1];
		printf("%s\n", tag.c_str());
		GetSceneManager.sceneMap.insert(std::make_pair(tag, i));

		i->sceneWidth = GetSystem.width;
		i->sceneHeight = GetSystem.height;

		i = va_arg(args, Scene*);
	}

	va_end(args);
}

void Resource::CreateMap(const std::string &srcPath, const std::string &dstPath, const std::string &dstFileName)
{
	std::ofstream out((dstPath + dstFileName + ".map").c_str());

	_finddata_t fd;
	long handle = _findfirst((srcPath + "*.*").c_str(), &fd);

	if (handle == -1)
		return;

	do
	{
		if (!strcmp(fd.name, ".") || !strcmp(fd.name, "..") || !strcmp(fd.name, "Thumbs.db")) {
			continue;
		}

		std::string tag = fd.name;
		tag = tag.substr(0, tag.find("."));

		out << srcPath + fd.name << " " << tag << std::endl;
	} while (_findnext(handle, &fd) != -1);

	_findclose(handle);

	out.close();
}

void Resource::CreateMap(const std::string &srcPath, const std::string &dstPath, const std::string &dstFileName, const std::string &extension)
{
	std::ofstream out((dstPath + dstFileName + ".map").c_str());

	_finddata_t fd;
	long handle = _findfirst((srcPath + "*" + extension).c_str(), &fd);

	if (handle == -1)
		return;

	do
	{
		if (!strcmp(fd.name, ".") || !strcmp(fd.name, "..") || !strcmp(fd.name, "Thumbs.db")) {
			continue;
		}

		std::string tag = fd.name;
		tag = tag.substr(0, tag.find("."));

		out << srcPath + fd.name << " " << tag << std::endl;
	} while (_findnext(handle, &fd) != -1);

	_findclose(handle);

	out.close();
}

void Resource::LoadTextureMap(const char *path)
{
	if (GetResourceManager.LoadTextureMap(path)<0)
	{
		GetSystem.Exit();
	}
}


void Resource::LoadSEMap(const char *path)
{
	if (GetResourceManager.LoadSEMap(path)<0)
	{
		printf("SEMap not loaded");
		return;
	}
}

void Resource::LoadBGMMap(const char *path)
{
	if (GetResourceManager.LoadBGMMap(path)<0)
	{
		printf("BGMMap not loaded");
		return;
	}
}

void Resource::LoadFontMap(const char *path)
{
	if (GetResourceManager.LoadFontMap(path) < 0)
	{
		printf("FontMap not loaded");
		return;
	}
}