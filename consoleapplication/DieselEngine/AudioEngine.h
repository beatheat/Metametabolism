#ifndef _AUDIOENGINE_H_
#define _AUDIOENGINE_H_

#define GetAudio AudioEngine::GetInstance()

#include<SDL_mixer.h>
#include<string>

using namespace std;

class AudioEngine
{
public:
	static AudioEngine *ae;

private:
	AudioEngine(){};

public:
	static AudioEngine &GetInstance();
	void Release();

public:
	void PlaySE(const string &name);
	void PauseSE(const string &name);
	void ResumeSE(const string &name);

	void SetSEVolume(double volume);
	void SetSEVolume(const string &name, double volume);

public:
	void PlayBGM(const string &name);
	void PauseBGM(const string &name);
	void ResumeBGM(const string &name);

	void FadePlayBGM(const string &name);
	void FadePauseBGM(const string &name);

	void SetBGMVolume(double volume);
	void SetBGMVolume(const string &name, double volume);
};

#endif