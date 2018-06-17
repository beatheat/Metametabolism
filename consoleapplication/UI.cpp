#include"UI.h"

#include"Graph.h"
#include"Data.h"
#include<string>

void UI::Initialize()
{
	tUI = GetResourceManager.GetTexture("ui");
	tUI->alpha = 0.25;

	tMsgbox = GetResourceManager.GetTexture("msgBox");
	tMsgbox->alpha = 0.35;

	tMsgbox2 = GetResourceManager.GetTexture("box2");
	tMsgbox2->alpha = 0.35;
	tMsgbox3 = GetResourceManager.GetTexture("box3");
	tMsgbox3->alpha = 0.35;

	for (int i = 0; i < 11; i++){
		msglist[i] = Label::Create(GetFontManager.GetFont("pixel", 15), 75, 182 - i * 15);
		msglist[i]->SetColor(255, 255, 255);
	}

	for (int i = 0; i < 21; i++){
		msglist2[i] = Label::Create(GetFontManager.GetFont("pixel", 15), 75, 100 + 170 + 90 + 5  + 160 - 15 - i * 15);
		msglist2[i]->SetColor(255, 255, 255);
	}

	for (int i = 0; i < 3; i++){
		msglist3[i] = Label::Create(GetFontManager.GetFont("pixel", 15), 75, 100 + 330 + 35 + 90 + 5 + 25 - 15- i * 15);
		msglist3[i]->SetColor(255, 255, 255);
	}

	parent->CreateObjectWithTag(new Graph, 800 - 75, 80+5,"oxygen");
	parent->CreateObjectWithTag(new Graph, 800 - 75, 145+85,"heart");
	parent->CreateObjectWithTag(new Graph, 800 - 75, 290+85 , "sugar");
	parent->CreateObjectWithTag(new Graph, 800 - 75, 145 * 3 + 85, "chole");

	keyevent = KeyboardEvent::Create();
}

void UI::Step()
{
	while (true){
		if (Data::message.size() > 11){
			Data::message.pop_back();
		}
		else break;
	}

	while (true){
		if (Data::message2.size() > 21){
			Data::message2.pop_back();
		}
		else break;
	}

	while (true){
		if (Data::message3.size() > 3){
			Data::message3.pop_back();
		}
		else break;
	}


	int i = 0;
	for each(auto iter in Data::message){
		msglist[i++]->SetText(iter);
	}
	i = 0;
	for each(auto iter in Data::message2){
		msglist2[i++]->SetText(iter);
	}
	i = 0;
	for each(auto iter in Data::message3){
		msglist3[i++]->SetText(iter);
	}
}

void UI::Draw()
{
	DrawTexture(tUI, GetSystem.width / 2, GetSystem.height / 2);
	DrawTexture(tMsgbox, 75, 100+5);
	DrawTexture(tMsgbox2, 75, 100 + 170 + 90+5);
	DrawTexture(tMsgbox3, 75, 100 + 330 + 35 + 90+5);
	int i = 0;
	for each(auto iter in msglist) iter->Draw();
	for each(auto iter in msglist2) iter->Draw();
	for each(auto iter in msglist3) iter->Draw();

	if (keyevent->GetKeyPressed(DI_KEYCODE_ESCAPE))
	{
		if (!parent->isPause) parent->Pause();
		else if (parent->isPause) parent->Resume();
	}
}

void UI::Release()
{

}