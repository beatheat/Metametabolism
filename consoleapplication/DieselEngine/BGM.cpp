#include"BGM.h"

BGM *BGM::Create(const std::string &path)
{
	BGM *bgm = new BGM;
	if ((bgm->chunk = Mix_LoadWAV(path.c_str())) == NULL)
		printf(("Error :" + path + "is wrong\n").c_str());
	bgm->channel = -1;
	bgm->name = path;
	bgm->isPlaying = false;
	bgm->volume = 0.5;
	return bgm;
}

void BGM::Release()
{
	Mix_FreeChunk(chunk);
	name.clear();
	delete this;
}
void BGM::Play()
{
	if (isPlaying) return;
	if (channel == -1)
	{
		channel = Mix_PlayChannel(-1, chunk, 0);
		Mix_Volume(channel, volume * 128);
		isPlaying = true;
	}
}

void BGM::Pause()
{
	if (channel == -1)
	{
		printf(("Error: " + name + " channel not allocated\n").c_str());
		return;
	}
	if (isPlaying) 
	{
		isPlaying = false;
		Mix_Pause(channel);
	}
}

void BGM::Resume()
{
	if (channel == -1)
	{
		printf(("Error: " + name + " channel not allocated\n").c_str());
		return;
	}
	if (!isPlaying) 
	{
		isPlaying = true;
		Mix_Resume(channel);
	}
}

void BGM::FadeIn(double frame)
{
	if (isPlaying) return;
	if (channel == -1)
	{
		isPlaying = true;
		channel = Mix_FadeInChannel(-1, chunk, -1, frame);
	}
}

void BGM::FadeOut(double frame)
{
	if (channel == -1)
	{
		printf(("Error: " + name + " channel not allocated\n").c_str());
		return;
	}
	if (isPlaying)
	{
		isPlaying = false;
		Mix_FadeOutChannel(channel, frame);
	}
}

void BGM::SetVolume(double volume)
{
	this->volume = volume;
	if (channel == -1)
	{
		return;
	}
	if (volume > 1.0 || volume < 0.0)
	{
		printf("Error: volume range out");
		return;
	}
	Mix_Volume(channel, volume * 128);
}