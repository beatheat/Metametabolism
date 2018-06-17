#ifndef _TITLESCENE_H_
#define _TITLESCENE_H_

#include"Diesel.h"

#include"Title.h"

class TitleScene : public Scene
{
public:
	void Initialize(){
		CreateObject(new Title);
	}
	void Release(){
		
	}
};

#endif