#ifndef _FRAME_H_
#define _FRAME_H_

#define GetFrame Frame::GetInstance()

class Frame
{
private:
	Frame() : fps(0), oldTick(0), nowTick(0), tick(0), speed(60){};

private:
	static Frame *fm;

public:
	double fps;

	int    speed;

	unsigned long  oldTick;
	unsigned long  nowTick;
	unsigned long  tick;

public:
	static Frame &GetInstance();

	void Release();

public:

};

#endif