#include"Human.h"

#include"Data.h"
#include<fstream>

int die = 0;
double dx = 0;

void Human::Initialize()
{
	lungs = AnimationManager::Create(GetResourceManager.GetTexture("lungs3"), 37, 42);
	lungs->texture->SetScale(3, 3);
	lungs->AddAnimation("suchuk", 0, 7, 0, 2, false);
	lungs->AddAnimation("pengchang", 0, 7, 1, 4, false);

	hearts = AnimationManager::Create(GetResourceManager.GetTexture("hearts"), 22, 27);
	hearts->texture->SetScale(3, 3);
	hearts->AddAnimation("suchuk", 0, 5, 1, 1, false);
	hearts->AddAnimation("pengchang", 0, 5, 0, 2, false);
	hearts->texture->angle = -20;
	hani = false;

	liver = AnimationManager::Create(GetResourceManager.GetTexture("liver"), 40, 40);
	liver->texture->SetScale(2.5, 2.5);
	liver->AddAnimation("move", 0, 4, 0, 2, false);

	pancreas = AnimationManager::Create(GetResourceManager.GetTexture("pancreas"), 40, 20);
	pancreas->texture->SetScale(2, 2);
	pancreas->AddAnimation("move", 0, 4, 0, 2, false);

	lsuchuk = false;

	keyeventQ = KeyboardEvent::Create();
	keyeventW = KeyboardEvent::Create();
	keyeventE = KeyboardEvent::Create();
	keyeventR = KeyboardEvent::Create();

	timer_lung = Timer::Create();
	timer_heart = Timer::Create();
	timer_cholesterol = Timer::Create();
	timer_sugar = Timer::Create();

	beat = 0;
	Data::heartbeat.push_front(40);
	Data::heartbeat.push_front(40);

	oxydown = Timer::Create();
	oxypengchang = Timer::Create();
	oxygen = 100;
	oxypeng = false;

	sugar = 150;
	Data::bloodsugar.push_front(150/6);
	Data::bloodsugar.push_front(150/6);

	Data::oxyinlungs.push_front(100);
	Data::oxyinlungs.push_front(100);


	Data::cholesterol.push_front(150/4);
	Data::cholesterol.push_front(150/4);
	cholesterol = 150;

	random.SetSeed(0);
	LoadBody();
	SetProfile();
	infor = Label::Create(GetFontManager.GetFont("pixelb", 8), GetSystem.width/2, 450);
	infor->SetText(name + L"(" + age + L")");
	infor->scaleX = infor->scaleY = 4.5;
	inforL = Label::Create(GetFontManager.GetFont("pixelb", 8), GetSystem.width / 2 + 1, 450 +1);
	inforL->SetText(name + L"(" + age + L")");
	inforL->scaleX = inforL->scaleY = 4.5;
	inforL->SetColor(255, 255, 255);
	inforDet = Label::Create(GetFontManager.GetFont("pixel", 8), GetSystem.width/2, 460);
	inforDet->scaleX = inforDet->scaleY = 2.5;
	inforDet->SetTextInBox(L"MY NAME IS " + name +  L". "+ hobby + L"! MY PARENTS HAVE SUFFERED FROM XX.",110,600);
	inforDet->alpha = 0;
	tMsg = GetResourceManager.GetTexture("msg");
	tMsg->SetScale(3, 3);
	tMsg->alpha = 0;

	SetSymptom();
	SetEvent();

	tDead = GetResourceManager.GetTexture("dead");
	tDead->SetScale(0, 0);
}
void Human::Step()
{
	if (keyeventQ->GetKeyPressed(DI_KEYCODE_Q)){
		lsuchuk = false;
		lungs->Stop();
		lungs->Play("pengchang", 7 - lungs->GetCurrentStep());
	}
	if (keyeventQ->GetKeyReleased(DI_KEYCODE_Q)){
		lsuchuk = true;
		oxypeng = false;
		lungs->Stop();
		lungs->Play("suchuk",7 - lungs->GetCurrentStep());
	}

	if (keyeventW->GetKeyPressed(DI_KEYCODE_W) && !hani){
		hani = true;
		hearts->Stop();
		hearts->Play("pengchang");
		beat++;
		sugar -= 0.8;
	}

	if (keyeventE->GetKeyPressed(DI_KEYCODE_E)){
		sugar += 3.6;
		liver->Play("move");
	}

	if (keyeventR->GetKeyPressed(DI_KEYCODE_R)){
		sugar -= 3;
		pancreas->Play("move");
	}

	if (GetKeyboard.Check(DI_KEYCODE_F)){
		inforDet->alpha = 1;
		tMsg->alpha = 1;
	}
	else {
		inforDet->alpha = 0;
		tMsg->alpha = 0;
	}

	if (hearts->IsAnimationEnd() && hearts->GetCurrentAnimation() == "pengchang") 
		hearts->Play("suchuk");
	if (hearts->GetCurrentStep() == 5 && hearts->GetCurrentAnimation() == "suchuk"){
		hani = false;
	}
	
	oxygen = !lsuchuk && !oxypeng ? oxygen+=0.3 : oxygen;
	if (oxypengchang->Tick(180) && !lsuchuk) oxypeng = true;
	if (oxydown->Tick(5)){
		oxygen -= 0.5;
	}
	
	sugar = !lsuchuk ? sugar -= 0.2 : sugar;
	sugar -= 0.01;
	if (sugar <= 0) sugar = 0;
	if (sugar >= 600) sugar = 600;

	if (cholesterol >= 400) cholesterol = 400;
	if (cholesterol <= 0) cholesterol = 0;
	
	if (beat <= 0) beat = 0;

	if (oxygen >= 100) oxygen = 100;
	if (oxygen <= 0) oxygen = 0;

	if (timer_lung->Tick(60)){
		if (Data::oxyinlungs.size() >= 34){
			Data::oxyinlungs.pop_back();
		}
		Data::oxyinlungs.push_front(oxygen);
		if (oxygen < 100 - 19) Data::message.push_front(L"NO OXYGEN!");

		if (oxygen >= 100){

		}
		if (oxygen < 60){
			//die = 1;
			tHeadAche->alpha = 1;
		}
		if (oxygen> 60) tHeadAche->alpha = 0;
		if (oxygen < 30){
			//die = 2;
			tHeadDie->alpha = 1;
		}
		
	}

	if (timer_heart->Tick(180)){
		if (Data::heartbeat.size() >= 34){
			Data::heartbeat.pop_back();
		}
		Data::heartbeat.push_front(beat * 10);
		if (beat > 5){
			Data::message.push_front(L"OVER BEAT!");
		}
		if (beat < 3) {
			Data::message.push_front(L"NONE BEAT!");
		}
		if (beat < 3) tHeadAche->alpha = 1;
		else tHeadAche->alpha = 0;
		if (beat == 0) tHeadDie->alpha = 1;
		beat = 0;
	}

	if (timer_sugar->Tick(60)){
		if (Data::bloodsugar.size() >= 34){
			Data::bloodsugar.pop_back();
		}
		Data::bloodsugar.push_front(sugar/6);
		if (sugar / 6 < 9)
			Data::message.push_front(L"LOW SUGAR!");
		if (sugar / 6 >  50)
			Data::message.push_front(L"HIGH SUGAR!");



		if (sugar <= 50) low_sugar_shock += 10;
		if (sugar >= 60) low_sugar_shock -= 15;

		if (low_sugar_shock <= 0) low_sugar_shock = 0;
		if (low_sugar_shock >= 200) low_sugar_shock = 200;

		if (low_sugar_shock >= 100 && !blow_sugar_shock){
			blurredVision += 100;
			doubleVision += 100;
			dizziness += 100;
			hunger += 100;
			blow_sugar_shock = true;
			Symptom(0, 4);
		}

		if (low_sugar_shock <= 90&&blow_sugar_shock){
			blurredVision -= 100;
			doubleVision -= 100;
			dizziness -= 100;
			hunger -= 100;
			blow_sugar_shock = false;
		}

		if (low_sugar_shock >= 130 && !clow_sugar_shock){
			tremor += 100;
			headache += 100;
			fatigue += 100;
			clow_sugar_shock = true;
			Symptom(4, 8);
		}

		if (low_sugar_shock <= 120 && clow_sugar_shock){
			tremor -= 100;
			headache -= 100;
			fatigue -= 100;
			clow_sugar_shock = false;
		}

		if (low_sugar_shock >= 160 && !dlow_sugar_shock){
			irritability += 100;
			anxiety += 100;
			chills += 100;
			nightsweat += 100;
			convulsions += 100;
			dlow_sugar_shock = true;
			Symptom(8,12);
		}

		if (low_sugar_shock <= 150 && dlow_sugar_shock){
			irritability -= 100;
			anxiety -= 100;
			chills -= 100;
			nightsweat -= 100;
			convulsions -= 100;
			dlow_sugar_shock = false;
		}
		//Symptom();
	}

	if (timer_cholesterol->Tick(120)){
		if (Data::cholesterol.size() >= 34){
			Data::cholesterol.pop_back();
		}
		Data::cholesterol.push_front(cholesterol/4);
		//msg
	}
	if (tHeadDie->alpha == 1){
		dx = (3 - tDead->scaleX) / 30 + (dx*0.65);
		tDead->scaleX += dx;
		tDead->scaleY += dx;
	}
}


void Human::Draw()
{
	DrawBody(GetSystem.width/2,GetSystem.height/2 - 80);
	lungs->Draw(GetSystem.width/2,GetSystem.height/2-30 - 60);
	pancreas->Draw(GetSystem.width / 2 + 15, GetSystem.height / 2 );
	liver->Draw(GetSystem.width / 2, GetSystem.height / 2 - 20);
	hearts->Draw(GetSystem.width / 2, GetSystem.height / 2-20 - 60);
	inforL->Draw();
	infor->Draw();
	DrawTexture(tMsg, GetSystem.width / 2, 450);
	inforDet->Draw();
	DrawTexture(tDead, GetSystem.width/2, GetSystem.height/2);
}

void Human::Release()
{

}

void Human::DrawBody(double x, double y)
{
	DrawTexture(tBody, x, y);
	DrawTexturePart(tHead, x, y - 53.6 * 3 + 9, headNum * 35, 0, 35, 35);
	DrawTexturePart(tHeadAche, x, y - 53.6 * 3 + 9, headNum * 35, 0, 35, 35);
	DrawTexturePart(tHeadDie, x, y - 53.6 * 3 + 9, headNum * 35, 0, 35, 35);
	DrawTexture(tArmLeft, x - 50 * 3, y - 5 * 3);
	DrawTexture(tArmRight, x + 50 * 3, y - 5 * 3);
	DrawTexture(tHandLeft, x - 50 * 3, y + 20 * 3);
	DrawTexture(tHandRight, x + 50 * 3, y + 20 * 3);
	DrawTexture(tHbj, x, y + 50 * 3);
	DrawTexture(tJarRight, x + 55 * 3, y + 85 * 3);
	DrawTexture(tJarLeft, x - 55 * 3, y + 85 * 3);
	DrawTexture(tFootRight, x + 55 * 3, y + 110 * 3);
	DrawTexture(tFootLeft, x - 55 * 3, y + 110 * 3);
	DrawTexturePart(tEyeLeft, x - 6 * 3 + 2, y - 53.6 * 3, eyeNum * 10, 0, 10, 8);
	DrawTexturePart(tEyeRight, x + 6 * 3 + 2, y - 53.6 * 3, eyeNum * 10, 0, 10, 8);
	DrawTexturePart(tNose, x + 3, y - 53.6 * 3 + 15, noseNum * 10, 0, 10, 10);
	DrawTexturePart(tMouth, x + 3, y - 53.8 * 3 + 40, mouthNum * 15, 0, 15, 10);
	DrawTexturePart(tHair, x , y - 53.8 * 3 - 25, hairNum * 40, 0, 40, 40);
}

void Human::LoadBody()
{
	std::string str;
	int r = random.NextInt(4);
	if (r % 4 == 0) str = "b";
	else if(r % 4 == 1) str = "w";
	else if (r % 4 == 1) str = "y";
	else str = "g";
	tBody = GetResourceManager.GetTexture(str + "-3-body");
	tHead = GetResourceManager.GetTexture(str + "-3-heads1");
	tHeadAche = GetResourceManager.GetTexture(str + "-3-heads2");
	tHeadDie = GetResourceManager.GetTexture(str + "-3-heads3");
	tArmLeft = GetResourceManager.GetTexture(str + "-3-arm");
	tArmRight = GetResourceManager.GetTexture(str + "-3-arm");
	tHandLeft = GetResourceManager.GetTexture(str + "-3-hand");
	tHandRight = GetResourceManager.GetTexture(str + "-3-hand");
	tHbj = GetResourceManager.GetTexture(str + "-3-hbj");
	tJarRight = GetResourceManager.GetTexture(str + "-3-jar");
	tJarLeft = GetResourceManager.GetTexture(str + "-3-jar");
	tFootRight = GetResourceManager.GetTexture(str + "-3-foot");
	tFootLeft = GetResourceManager.GetTexture(str + "-3-foot");
	tEyeLeft = GetResourceManager.GetTexture("eyes");
	tEyeRight = GetResourceManager.GetTexture("eyes");
	tNose = GetResourceManager.GetTexture("noses");
	tMouth = GetResourceManager.GetTexture("mouths");
	tHair = GetResourceManager.GetTexture("hairs");
	
	eyeNum = random.NextInt(9);
	noseNum = random.NextInt(10);
	mouthNum = random.NextInt(10);
	hairNum = random.NextInt(10);
	headNum = random.NextInt(3);

	tBody->scaleX = 3.0;
	tBody->scaleY = 3.0;
	tHead->scaleX = 3.0;
	tHead->scaleY = 3.0;
	tHeadAche->scaleX = 3.0;
	tHeadAche->scaleY = 3.0;
	tHeadDie->scaleX = 3.0;
	tHeadDie->scaleY = 3.0;
	tArmLeft->scaleX = 3.0;
	tArmLeft->scaleY = 3.0;
	tArmRight->scaleX = -3.0;
	tArmRight->scaleY = 3.0;
	tHandLeft->scaleX = 3.0;
	tHandLeft->scaleY = 3.0;
	tHandRight->scaleX = -3.0;
	tHandRight->scaleY = 3.0;
	tHbj->scaleX = 3.0;
	tHbj->scaleY = 3.0;
	tJarRight->scaleX = -3.0;
	tJarRight->scaleY = 3.0;
	tJarLeft->scaleX = 3.0;
	tJarLeft->scaleY = 3.0;
	tFootRight->scaleX = -3.0;
	tFootRight->scaleY = 3.0;
	tFootLeft->scaleX = 3.0;
	tFootLeft->scaleY = 3.0;
	tEyeLeft->scaleX = 3.0;
	tEyeLeft->scaleY = 3.0;
	tEyeRight->scaleX = -3.0;
	tEyeRight->scaleY = 3.0;
	tNose->scaleX = 3.0;
	tNose->scaleY = 3.0;
	tMouth->scaleX = 3.0;
	tMouth->scaleY = 3.0;
	tHair->scaleX = 3.0;
	tHair->scaleY = 3.0;

	tHeadAche->alpha = 0;
	tHeadDie->alpha = 0;
}

void Human::SetProfile()
{
	wifstream in;
	in.open("Resource\\names.txt");
	std::wstring tmp;
	int value = random.NextInt(312);
	for (int i = 0; i < value; i++) in >> tmp;
	in.close();
	name = tmp;
	gender = random.NextInt(2) % 2 == 0 ? L"male" : L"female";
	age = std::to_wstring(random.NextInt(18, 23));
	height = std::to_wstring(random.NextInt(140, 220));
	weight = std::to_wstring(random.NextInt(30, 180));
	wifstream in1, in2;
	in1.open("Resource\\things.txt");
	in2.open("Resource\\verbs.txt");
	std::wstring tmp1, tmp2;
	wchar_t buf[255];
	value = random.NextInt(31);
	for (int i = 0; i < value; i++) in1 >> tmp1;
	value = random.NextInt(33);
	for (int i = 0; i < value; i++) 
		in2.getline(buf, 255);
	tmp2 = buf;
	in1.close();
	in2.close();
	hobby = L"I LIKE TO " + tmp2 + L" " + tmp1;
}

void Human::SetEvent()
{
	allEvent[0] = low_sugar_shock = 0;
	allEvent[1] = high_sugar_shock = 0;
	blow_sugar_shock = false;
}

void Human::SetSymptom()
{
	
	sSymptom[0] = L"B.VISION"	;
	sSymptom[1] = L"D.VISION"		;
	sSymptom[2] = L"DIZZINESS"			;
	sSymptom[3] = L"HUNGER"			;
	sSymptom[4] = L"TREMOR"			;
	sSymptom[5] = L"HEADACHE"			;
	sSymptom[6] = L"FATIGUE"			;
	sSymptom[7] = L"IRRITABILITY"		;
	sSymptom[8] = L"ANXIETY"			;
	sSymptom[9] = L"CHILLS"			;
	sSymptom[10] = L"NIGHT SWEATS"		;
	sSymptom[11] = L"CONVULSION"        ;



	blurredVision = 0;
	doubleVision = 0;
	dizziness = 0;
	hunger = 0;
	tremor = 0;
	headache = 0;
	fatigue = 0;
	irritability = 0;
	anxiety = 0;
	chills = 0;
	nightsweat = 0;
	convulsions = 0;

	allSymptom[0] = &blurredVision;
	allSymptom[1] = &doubleVision  ;
	allSymptom[2] = &dizziness;
	allSymptom[3] = &hunger;
	allSymptom[4] = &tremor;
	allSymptom[5] = &headache;
	allSymptom[6] = &fatigue;
	allSymptom[7] = &irritability;
	allSymptom[8] = &anxiety;
	allSymptom[9] = &chills;
	allSymptom[10] = &nightsweat;
	allSymptom[11] = &convulsions;

	allvSymptom[0] = &vblurredVision;
	allvSymptom[1] = &vdoubleVision;
	allvSymptom[2] = &vdizziness;
	allvSymptom[3] = &vhunger;
	allvSymptom[4] = &vtremor;
	allvSymptom[5] = &vheadache;
	allvSymptom[6] = &vfatigue;
	allvSymptom[7] = &virritability;
	allvSymptom[8] = &vanxiety;
	allvSymptom[9] = &vchills;
	allvSymptom[10] = &vnightsweat;
	allvSymptom[11] = &vconvulsions;

	for (int i = 0; i < SYMPTOMNUM; i++){
		*allvSymptom[i] = random.NextInt(20);
		*allvSymptom[i] += 90;
	}
}

void Human::Event()
{

}

void Human::Symptom()
{
	list<std::wstring> tmp;
	for (int i = 0; i < SYMPTOMNUM; i++){
		if (*allSymptom[i] <= *allvSymptom[i]){
			tmp.push_front(sSymptom[i]);
			printf("i\n");
		}
	}
	for (auto i = tmp.begin(); i != tmp.end();)
	{
		for (auto j = Data::message2.begin(); j != Data::message2.end();)
		{
			if (i == j){
				j = Data::message2.erase(i);
				printf("o\n");
			}
			else j++;
		}
		i++;
	}
}

void Human::Symptom(int a,int b)
{
	for (int i = a; i < b; i++){
		if (*allSymptom[i] > *allvSymptom[i]){
			Data::message2.push_front(sSymptom[i]);
		}
	}
}