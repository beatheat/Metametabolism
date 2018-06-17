#include"FadeIn.h"


void FadeIn::Initialize()
{
	tColor = GetResourceManager.GetTexture("black");
}

void FadeIn::Step()
{
	if (tColor->alpha > 0.0){
		tColor->alpha -= 0.02;
	}
}

void FadeIn::Draw()
{
	DrawTexture(tColor, GetSystem.width / 2, GetSystem.height / 2);
}

void FadeIn::Release()
{

}