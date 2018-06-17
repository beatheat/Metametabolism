#include"Title.h"

#include"FadeOut.h"

void Title::Initialize()
{
	tTitle = GetResourceManager.GetTexture("title");
	tTitle->scaleX = tTitle->scaleY = 0;

	tStart[0] = GetResourceManager.GetTexture("start");
	tStart[1] = GetResourceManager.GetTexture("startr");
	tExit[0] = GetResourceManager.GetTexture("exit");
	tExit[1] = GetResourceManager.GetTexture("exitr");
	tStart[0]->alpha = 0;
	tExit[0]->alpha = 0;
	tStart[1]->alpha = 0;
	tExit[1]->alpha = 0;


	tStart[0]->SetScale(2, 2);
	tStart[1]->SetScale(2.2, 2.2);
	tExit[0]->SetScale(2, 2);
	tExit[1]->SetScale(2.2, 2.2);
	
	random.SetSeed(0);

	cStart = Clickable::CreateRectangle(this, GetSystem.width / 2, GetSystem.height / 2 + 80, tStart[0]->width * 2, tStart[0]->height * 2);
	cExit = Clickable::CreateRectangle(this, GetSystem.width / 2, GetSystem.height / 2 + 160, tExit[0]->width * 2, tExit[0]->height * 2);

	start = exit = 0;
	timer = Timer::Create();
	count = 0;
	first = false;
}


void Title::Step()
{
	if (tTitle->scaleX < 3.0) tTitle->scaleX = tTitle->scaleY += 0.1;
	if (tTitle->scaleX > 3.0) first = true;
	dx = (3 - tTitle->scaleX) / 30 + (dx*0.65);
	tTitle->scaleX += dx;
	tTitle->scaleY += dx;
	if (first){
		if (tStart[0]->alpha < 1){
			tStart[0]->alpha += 0.05;
			tStart[1]->alpha += 0.05;
			tExit[0]->alpha += 0.05;
			tExit[1]->alpha += 0.05;
		}
	}
	if (cStart->IsReleased(parent->mouse))
	{
		//GetSceneManager.ReplaceScene("GameScene");
		parent->CreateObjectWithTag(new FadeOut, "GameScene");
	}
	if (cStart->IsOn(parent->mouse))
	{
		start = 1;
	}else start = 0;

	if (cExit->IsReleased(parent->mouse))
	{
		GetSystem.Exit();
	}
	if (cExit->IsOn(parent->mouse))
	{
		exit = 1;
	}else exit = 0;

	if (timer->Tick(60)){
		Hemo *hemo = new Hemo;
		hemo->texture = GetResourceManager.GetTexture("hemo");

		double scale = random.NextInt(100);
		scale /= 100.0;
		
		hemo->texture->Init(random.Next() % 360, 1, 2.5+scale,2.5+scale, 0.5, 0.5, 0, BLENDMODE_BLEND);
		hemo->x = random.NextInt(800);
		hemo->y = random.NextInt(150);
		hemo->y *= -1;
		hemo->speed_x = random.NextInt(4);
		hemo->speed_x -= 2;
		hemo->speed_y = random.NextInt(8)+4;
		hemo->speed_angle = random.NextInt(4);
		hemo->speed_angle -= 2;
		tHemo2.push_back(hemo);
	}
	Hemo *hemo = new Hemo;
	hemo->texture = GetResourceManager.GetTexture("hemo");

	double scale = random.NextInt(100);
	scale /= 100.0;

	hemo->texture->Init(random.Next() % 360, 1, 2.5 + scale, 2.5 + scale, 0.5, 0.5, 0, BLENDMODE_BLEND);
	hemo->x = random.NextInt(800);
	hemo->y = random.NextInt(150);
	hemo->y *= -1;
	hemo->speed_x = random.NextInt(4);
	hemo->speed_x -= 2;
	hemo->speed_y = random.NextInt(8) + 4;
	hemo->speed_angle = random.NextInt(4);
	hemo->speed_angle -= 2;
	tHemo.push_back(hemo);

	for (std::vector<Hemo*>::iterator i = tHemo.begin(); i < tHemo.end();){
		(*i)->x += (*i)->speed_x;
		(*i)->y += (*i)->speed_y;
		(*i)->texture->angle += (*i)->speed_angle;
		if ((*i)->y > 630){
			i = tHemo.erase(i);
		}
		else i++;
	}
	for (std::vector<Hemo*>::iterator i = tHemo2.begin(); i < tHemo2.end();){
		(*i)->x += (*i)->speed_x;
		(*i)->y += (*i)->speed_y;
		(*i)->texture->angle += (*i)->speed_angle;
		if ((*i)->y > 630){
			i = tHemo2.erase(i);
		}
		else i++;
	}
}

void Title::Draw()
{
	for (int i = 0; i < tHemo.size(); i++){
		DrawTexture(tHemo[i]->texture,tHemo[i]->x,tHemo[i]->y);
	}
	DrawTexture(tTitle, GetSystem.width / 2, GetSystem.height / 2 - 150);
	DrawTexture(tStart[start], GetSystem.width / 2, GetSystem.height / 2 + 80);
	DrawTexture(tExit[exit], GetSystem.width / 2, GetSystem.height / 2 + 160);
	for (int i = 0; i < tHemo2.size(); i++){
		DrawTexture(tHemo2[i]->texture, tHemo2[i]->x, tHemo2[i]->y);
	}
}

void Title::Release()
{

}