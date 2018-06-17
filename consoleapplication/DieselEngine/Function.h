#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <string>

#define GetFn Function::GetInstance()

class Function
{
private:
	Function(){};

private:
	static Function *fn;

public:
	static Function &GetInstance();

public:
	void Release();

	std::string *StringSplit(std::string strTarget, std::string strTok);

	bool CollisionRectToRect(double x1, double y1, int w1, int h1, double x2, double y2, int w2, int h2);
	bool CollisionRectToCircle(double x1, double y1, int w1, int h1, double x2, double y2, int d);
	bool CollisionCircleToCircle(double x1, double y1, int d1, double x2, double y2, int d2);
	bool CollisionPointToRect(double x1, double y1, double x2, double y2, int w, int h);
	bool CollisionPointToCircle(double x1, double y1, double x2, double y2, int d);

};

#endif