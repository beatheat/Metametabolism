#include"SE.h"

SE *SE::Create(const std::string &path)
{
	SE *se = new SE();
	if ((se->chunk = Mix_LoadWAV(path.c_str())) == NULL) 
		printf(("Error :" + path + "is wrong\n").c_str());
	se->channel = -1;
	se->name = path;
	se->volume = 0.5;
	return se;
}

void SE::Release()
{
	Mix_FreeChunk(chunk);
	name.clear();
	delete this;
}
void SE::Play()
{
	channel = Mix_PlayChannel(-1, chunk, 0);
	Mix_Volume(channel, volume * 128);
}

void SE::Pause()
{
	if (channel == -1)
	{
		printf(("Error: " + name + " channel not allocated\n").c_str());
		return;
	}
	Mix_Pause(channel);
}

void SE::Resume()
{
	if (channel == -1)
	{
		printf(("Error: " + name + " channel not allocated\n").c_str());
		return;
	}
	Mix_Resume(channel);
}

void SE::SetVolume(double volume)
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