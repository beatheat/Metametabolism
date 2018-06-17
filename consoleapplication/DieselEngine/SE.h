#ifndef _SE_H_
#define _SE_H_

#include<SDL_mixer.h>
#include<string>

class SE
{
public:
	Mix_Chunk *chunk;
	int channel;
	std::string name;
	double volume;
public:
	static SE *Create(const std::string &path);

	void Release();
		
	//Playifstop??
	void Play();
	void Pause();
	void Resume();

	void SetVolume(double volume);
};

#endif