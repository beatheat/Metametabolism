#include"ResourceManager.h"

#include "System.h"
#include "AudioEngine.h"

#include<SDL.h>
#include <iostream>
#include <fstream>

ResourceManager *ResourceManager::rm = 0;

ResourceManager &ResourceManager::GetInstance()
{
	if (rm == 0) rm = new ResourceManager();
	return *rm;
}

void ResourceManager::Release()
{
	for each(auto iterator in textureMap)
	{
		if (iterator.second != NULL) {
			SDL_DestroyTexture(iterator.second);
			iterator.second = NULL;
		}
	}
	textureMap.clear();


	for each(auto iterator in seMap) {
		iterator.second->Release();
	}
	seMap.clear();

	for each(auto iterator in bgmMap) {
		iterator.second->Release();
	}
	bgmMap.clear();

	GetAudio.Release();
}

int ResourceManager::LoadTextureMap(const char *path)
{
	std::ifstream in;

	in.open(path, std::ios::in);
	if (!in.is_open()) {
		printf("Error: TextureMap is not here");
		return -1;
	}

	std::string tmp;
	int count = 0;
	while (!in.eof()) { count += 1; in >> tmp; }
	in.clear();
	in.seekg(0, std::ios::beg);

	for (int i = 0; i < (count / 2); i++)
	{
		SDL_Texture *texture;
		in >> tmp;
		texture = IMG_LoadTexture(GetSystem.renderer, tmp.c_str());
		if (texture == NULL)
		{
			printf(("Error: " + tmp + " is wrong.").c_str());
			return -1;
		}
		in >> tmp;

		textureMap.insert(std::make_pair(tmp, texture));
	}

	in.close();

	return 0;
}

Texture *ResourceManager::GetTexture(const std::string &tag)
{
	Texture *texture = new Texture;
	texture->texture = textureMap[tag];
	SDL_QueryTexture(texture->texture, NULL, NULL, &texture->width, &texture->height);
	texture->Init(0, 1.0, 1.0, 1.0, 0.5, 0.5, 0, BLENDMODE_BLEND);
	return texture;
}


int ResourceManager::LoadSEMap(const char *path)
{
	std::ifstream in;

	in.open(path, std::ios::in);
	if (!in.is_open())
		return -1;

	std::string tmp;
	int count = 0;
	while (!in.eof()) { count += 1; in >> tmp; }
	in.clear();
	in.seekg(0, std::ios::beg);

	for (int i = 0; i < (count / 2); i++)
	{
		in >> tmp;

		SE *se = SE::Create(tmp);

		in >> tmp;
		seMap.insert(std::make_pair(tmp, se));
	}

	in.close();

	return 0;
}

int ResourceManager::LoadBGMMap(const char *path)
{
	std::ifstream in;

	in.open(path, std::ios::in);
	if (!in.is_open())
		return -1;

	std::string tmp;
	int count = 0;
	while (!in.eof()) { count += 1; in >> tmp; }
	in.clear();
	in.seekg(0, std::ios::beg);

	for (int i = 0; i < (count / 2); i++)
	{
		in >> tmp;

		BGM *bgm = BGM::Create(tmp);
		in >> tmp;
		bgmMap.insert(std::make_pair(tmp, bgm));
	}

	in.close();

	return 0;
}

int ResourceManager::LoadFontMap(const char *path)
{
	std::ifstream in;

	in.open(path, std::ios::in);
	if (!in.is_open())
		return -1;

	std::string tmp;
	int count = 0;
	while (!in.eof()) { count += 1; in >> tmp; }
	in.clear();
	in.seekg(0, std::ios::beg);

	for (int i = 0; i < (count / 2); i++)
	{
		in >> tmp;
		std::string str = tmp;
		in >> tmp;
		fontMap.insert(std::make_pair(tmp, str));
	}

	in.close();

	return 0;
}

