#include"Background.h"

void Back::Initialize()
{
	tBed = GetResourceManager.GetTexture("bed");
	tSofa = GetResourceManager.GetTexture("sofa");
	tBus = GetResourceManager.GetTexture("bus");
	tSubway = GetResourceManager.GetTexture("subway");

	tDarkhill = GetResourceManager.GetTexture("darkhill");
	tFlow = GetResourceManager.GetTexture("flow");

	foreground[0] = tBed;
	foreground[1] = tSofa;
	foreground[2] = tBus;
	foreground[3] = tSubway;

	background[0] = tDarkhill;
	background[1] = tFlow;

	for (int i = 0; i < FORENUM; i++){
		foreground[i]->SetScale(4.2, 4.2);
	}
	for (int i = 0; i < BACKNUM; i++){
		background[i]->SetScale(4, 4);
	}

	fsituation = 0;
	bsituation = 0;

	timer = Timer::Create();
	count_shake = 0;

	random.SetSeed(0);
}

void Back::Step()
{
	if (timer->Tick(60*10))
	{
		fsituation = random.NextInt(FORENUM);
		bsituation = random.NextInt(BACKNUM);
	}
	if (fsituation == 2){
		shake_x = random.NextInt(7);
		shake_x -= 12;
		shake_y = random.NextInt(7);
		shake_y -= 12;
	}
	else if (fsituation == 3){
		if (count_shake % 100 > 40 && count_shake % 100 < 50){
			shake_x = random.NextInt(3);
			shake_x -= 4;
			shake_y = random.NextInt(3);
			shake_y -= 4;
		}
		else shake_x = shake_y = 0;
	}
	else{
		shake_x = shake_y = 0;
	}
	x = x >= GetSystem.width ? 0 : x+=30;
	count_shake++;
}

void Back::Draw()
{
	DrawTexture(background[bsituation], GetSystem.width / 2 + x - GetSystem.width, GetSystem.height / 2);
	DrawTexture(background[bsituation], GetSystem.width / 2 + x, GetSystem.height / 2);
	DrawTexture(foreground[fsituation], GetSystem.width / 2 + shake_x, GetSystem.height / 2 + shake_y);
}

void Back::Release()
{

}