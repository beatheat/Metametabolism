#ifndef _ANIMATIONMANAGER_H_
#define _ANIMATIONMANAGER_H_

#include "Object.h"
#include "Timer.h"

typedef struct Animation
{
	std::string key;
	int start, end;
	int act;
	int interval;
	bool loop;
	Animation(int _start, int _end,int _act,int _interval, bool _loop) :
		start(_start), end(_end), act(_act), interval(_interval), loop(_loop){};
}Animation;

class AnimationManager
{
public:
	static AnimationManager *Create(Texture *texture, int width, int height);

	void Play(const std::string &tag);
	void Play(const std::string &tag, int step);
	void Pause();
	void Resume();
	void Stop();

	void Draw(double x, double y);

	bool IsAnimationEnd();


	std::string &GetCurrentAnimation();
	int GetCurrentStep();
	void AddAnimation(const std::string &tag, int start, int end,int act, int interval, bool loop);

	void Release();

private:
	void DrawPart(double x, double y, int step, int act);

	void Background();

public:
	Texture *texture;
private:
	Timer *timer;
	Animation *currentAnimation;

	std::map<std::string, Animation *> animationMap;

	bool isPlaying = false;

	bool isAnimationEnd = false;

	bool isFirst = true;

	int width, height;
	int step = 0;

};

#endif