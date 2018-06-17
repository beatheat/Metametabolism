#ifndef _MATH_H_
#define _MATH_H_

#define GetMath Math::GetInstance()

class Math
{
private:
	Math(){};

private:
	static Math *math;

	double sinTable[3600];
	double cosTable[3600];
	double tanTable[3600];

public:
	static Math &GetInstance();
	void Release();

	void CreateTable();

public:
	double Sin(double value);
	double Cos(double value);
	double Tan(double value);

	double FastInvSqrt(double value);
	double FastSqrt(double value){ return FastInvSqrt(value) * value; };

	double PointToDistance(double x1, double y1, double x2, double y2);
	double PointToDirection(double x1, double y1, double x2, double y2);
};

#endif