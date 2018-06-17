#include "AnimationManager.h"

#include "System.h"
#include "Camera.h"

#include<SDL.h>

AnimationManager *AnimationManager::Create(Texture *texture, int width, int height)
{
	auto am = new AnimationManager;
	am->timer = Timer::Create();
	am->texture = texture;

	am->width = width;
	am->height = height;

	return am;
}

void AnimationManager::AddAnimation(const std::string &tag, int start, int end,int act, int interval, bool loop)
{
	auto animation = new Animation(start, end, act, interval, loop);
	animation->key = tag;
	animationMap.insert(std::make_pair(tag, animation));

	if (isFirst)
	{
		currentAnimation = animationMap.begin()->second;
		isFirst = false;
	}
}

std::string &AnimationManager::GetCurrentAnimation()
{
	return currentAnimation->key;
}

int AnimationManager::GetCurrentStep()
{
	return step;
}


void AnimationManager::Play(const std::string &tag)
{
	if (!isPlaying)
	{
		currentAnimation = animationMap[tag];
		step = currentAnimation->start;
		timer->Reset();
		isPlaying = true;
	}
}

void AnimationManager::Play(const std::string &tag,int step)
{
	if (!isPlaying)
	{
		currentAnimation = animationMap[tag];
		this->step = step;
		timer->Reset();
		isPlaying = true;
	}
}

void AnimationManager::Pause()
{
	isPlaying = false;
}

void AnimationManager::Resume()
{
	isPlaying = true;
}

void AnimationManager::Stop()
{
	isPlaying = false;
	timer->Reset();
}

void AnimationManager::Background()
{
	if (isPlaying)
	{
		isAnimationEnd = false;
		if (timer->Tick(currentAnimation->interval))
		{
			step += 1;
			if (step > currentAnimation->end)
			{
				if (!currentAnimation->loop)
				{
					isPlaying = false;
					step = currentAnimation->end;
					isAnimationEnd = true;
				}
				else
				{
					isAnimationEnd = true;
					step = currentAnimation->start;
				}
			}
		}
	}
}

bool AnimationManager::IsAnimationEnd()
{
	return isAnimationEnd;
}

void AnimationManager::Draw(double x, double y)
{
	Background();
	DrawPart(x, y, step,currentAnimation->act);
}

void AnimationManager::DrawPart(double x, double y, int step,int act)
{
	int xcount = texture->width / width;

	step %= xcount;

	SDL_Rect src, dst;
	SDL_Point point;

	point.x = texture->centerX*width*texture->scaleX;
	point.y = texture->centerY*height*texture->scaleY;

	src.x = step * width;
	src.y = act *height;
	src.w = width;
	src.h = height;

	dst.x = x - point.x;
	dst.y = y - point.y;
	dst.w = src.w * texture->scaleX;
	dst.h = src.h * texture->scaleY;

	SDL_SetTextureColorMod(texture->texture, 255, 255, 255);
	SDL_SetTextureBlendMode(texture->texture, (SDL_BlendMode)texture->blendmode);
	SDL_SetTextureAlphaMod(texture->texture, texture->alpha*255.0);

	SDL_RenderCopyEx(GetSystem.renderer, texture->texture, &src, &dst, texture->angle, &point, SDL_FLIP_NONE);
}

void AnimationManager::Release()
{
	timer->Release();

	for each(auto iterator in animationMap) {
		delete iterator.second;
	}
	animationMap.clear();

	delete this;
}