#include"FadeOut.h"

void FadeOut::Initialize()
{
	tColor = GetResourceManager.GetTexture("black");
	tColor->alpha = 0;
	count = 0;
}

void FadeOut::Step()
{
	if (tColor->alpha < 1.0){
		tColor->alpha += 0.02;
	}
	if (tColor->alpha >= 1.0 && count > 180){
		GetSceneManager.ReplaceScene(tag);
	}
	if (count < 200) count++;
}

void FadeOut::Draw()
{
	DrawTexture(tColor, GetSystem.width / 2, GetSystem.height / 2);	
}

void FadeOut::Release()
{

}