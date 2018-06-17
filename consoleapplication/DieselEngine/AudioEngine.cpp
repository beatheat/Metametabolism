#include"AudioEngine.h"

#include"ResourceManager.h"
#include"System.h"

AudioEngine *AudioEngine::ae = 0;

AudioEngine &AudioEngine::GetInstance()
{
	if (ae == 0) ae = new AudioEngine();
	return *ae;
}

void AudioEngine::Release()
{
	delete this;
}

void AudioEngine::PlaySE(const std::string &name)
{
	if (!GetResourceManager.seMap[name]) return;
	GetResourceManager.seMap[name]->Play();
}

void AudioEngine::PauseSE(const std::string &name)
{
	if (!GetResourceManager.seMap[name]) return;
	GetResourceManager.seMap[name]->Pause();
}

void AudioEngine::ResumeSE(const std::string &name)
{
	if (!GetResourceManager.seMap[name]) return;
	GetResourceManager.seMap[name]->Resume();
}

void AudioEngine::SetSEVolume(double volume)
{
	for each(auto iterator in GetResourceManager.seMap){
		iterator.second->SetVolume(volume);
	}
}

void AudioEngine::SetSEVolume(const string &name, double volume)
{
	GetResourceManager.seMap[name]->SetVolume(volume);
}

void AudioEngine::PlayBGM(const std::string &name)
{
	if (!GetResourceManager.bgmMap[name]) return;
	GetResourceManager.bgmMap[name]->Play();
}

void AudioEngine::PauseBGM(const std::string &name)
{
	if (!GetResourceManager.bgmMap[name]) return;
	GetResourceManager.bgmMap[name]->Pause();
}

void AudioEngine::ResumeBGM(const std::string &name)
{
	if (!GetResourceManager.bgmMap[name]) return;
	GetResourceManager.bgmMap[name]->Resume();
}

void AudioEngine::FadePlayBGM(const std::string &name)
{
	if (!GetResourceManager.bgmMap[name]) return;
	GetResourceManager.bgmMap[name]->FadeIn(50);
}

void AudioEngine::FadePauseBGM(const std::string &name)
{
	if (!GetResourceManager.bgmMap[name]) return;
	GetResourceManager.bgmMap[name]->FadeOut(50);
}

void AudioEngine::SetBGMVolume(double volume)
{
	for each(auto iterator in GetResourceManager.bgmMap){
		iterator.second->SetVolume(volume);
	}
}

void AudioEngine::SetBGMVolume(const std::string &name, double volume)
{
	if (!GetResourceManager.bgmMap[name]) return;
	GetResourceManager.bgmMap[name]->SetVolume(volume);
}