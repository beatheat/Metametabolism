#ifndef _HUMAN_H_
#define _HUMAN_H_

#include"Diesel.h"

#include<vector>

#define EVENTNUM 1
#define SYMPTOMNUM 12

class Human : public Object
{
public:
	AnimationManager *lungs;
	bool lsuchuk;

	AnimationManager *hearts;
	bool hani;

	AnimationManager *liver;
	AnimationManager *pancreas;

	bool lfirst;

	KeyboardEvent *keyeventQ;
	KeyboardEvent *keyeventW;
	KeyboardEvent *keyeventE;
	KeyboardEvent *keyeventR;
public:
	Timer *timer_lung;
	Timer *timer_heart;
	Timer *timer_sugar;
	Timer *timer_cholesterol;

	double oxygen;
	Timer *oxydown;
	Timer *oxypengchang;
	bool oxypeng;

	int beat;

	double cholesterol;

	double sugar;

	Random random;
public:
	Texture *tHead;
	Texture *tHeadAche;
	Texture *tHeadDie;
	Texture *tBody;
	Texture *tArmRight;
	Texture *tArmLeft;
	Texture *tHandRight;
	Texture *tHandLeft;
	Texture *tHbj;
	Texture *tJarRight;
	Texture *tJarLeft;
	Texture *tFootRight;
	Texture *tFootLeft;
	Texture *tHair;

	Texture *tEyeLeft;
	Texture *tEyeRight;
	Texture *tNose;
	Texture *tMouth;

	int eyeNum;
	int noseNum;
	int mouthNum;
	int hairNum;
	int headNum;

	void LoadBody();
	void DrawBody(double x, double y);
public:
	std::wstring name;
	std::wstring gender;
	std::wstring age;
	std::wstring height;
	std::wstring weight;
	std::wstring hobby;

	void SetProfile();
	Label *infor;
	Label *inforL;
	Label *inforDet;
	Texture *tMsg;
	Texture *Box;

	//
	Texture *tDead;

public:
	int low_sugar_shock = 0;
	bool blow_sugar_shock = false;
	bool clow_sugar_shock = false;
	bool dlow_sugar_shock = false;

	int high_sugar_shock;

	int low_oxygen;
	bool blow_oxygen = false;
	bool clow_oxygen = false;

	int none_oxygen;
	bool bnone_oxygen = false;
	bool cnone_oxygen = false;

	int allEvent[EVENTNUM];

	void SetEvent();
	void Event();
public:
	std::wstring sSymptom[SYMPTOMNUM];

	int blurredVision;
	int doubleVision;
	int dizziness;
	int hunger;
	int tremor;
	int headache;
	int fatigue;
	int irritability;
	int anxiety;
	int chills;
	int nightsweat;
	int convulsions;

	int vblurredVision;
	int vdoubleVision;
	int vdizziness;
	int vhunger;
	int vtremor;
	int vheadache;
	int vfatigue;
	int virritability;
	int vanxiety;
	int vchills;
	int vnightsweat;
	int vconvulsions;

	int *allSymptom[SYMPTOMNUM];
	int *allvSymptom[SYMPTOMNUM];

	void SetSymptom();
	void Symptom();
	void Symptom(int a,int b);

public:
	void Initialize() override;
	void Step() override;
	void Draw() override;
	void Release() override;
};


#endif