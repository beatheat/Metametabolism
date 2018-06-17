#ifndef _BGM_H_
#define _BGM_H_

#include<SDL_mixer.h>
#include<string>

class BGM
{
public:
	Mix_Chunk *chunk;
	int channel;
	std::string name;
	bool isPlaying;
	double volume;

public:
	static BGM *Create(const std::string &path);

	void Release();

	void Play();
	void Stop();
	void Pause();
	void Resume();

	void FadeIn(double frame);
	void FadeOut(double frame);

	void SetVolume(double volume);
};

#endif