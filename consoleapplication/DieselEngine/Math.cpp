#include"Math.h"

#include<SDL.h>
#include<stdio.h>
#include<math.h>

Math *Math::math = 0;

Math &Math::GetInstance()
{
	if (math == NULL) math = new Math();
	return *math;
	
}

void Math::Release()
{
	delete math;
	math = NULL;
}

void Math::CreateTable()
{
	for (int i = 0; i < 3600; i++){
		double x = (double)i * M_PI / 180.0;
		sinTable[i] = sin(x);
		cosTable[i] = cos(x);
		tanTable[i] = tan(x);
	}
}

double Math::Sin(double value)
{
	if (value == 0) return 0;

	int idx = value * 10;

	if (value >= 0)
		idx %= 3601;
	else
		idx %= 3600;

	if (value >= 0)
		idx = 3600 - idx;

	int sign = 1;
	sign = (idx >= 0) ? 1 : -1;

	return -sinTable[sign*(int)idx];
}


double Math::Cos(double value)
{
	if (value == 0) return 1;

	int idx = value * 10;
	if (value >= 0)
		idx %= 3601;
	else
		idx %= 3600;

	if (value >= 0)
		idx = 3600 - idx;

	int sign = 1;
	sign = (idx >= 0) ? 1 : -1;

	return cosTable[sign*(int)idx];
}

inline double Math::Tan(double value)
{
	if (value == 0) return 0;

	int idx = value * 10;
	if (value >= 0)
		idx %= 3601;
	else
		idx %= 3600;

	if (value >= 0)
		idx = 3600 - idx;

	int sign = 1;
	sign = (idx >= 0) ? 1 : -1;

	return tanTable[sign*(int)idx];
}

double Math::PointToDistance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

double Math::PointToDirection(double x1, double y1, double x2, double y2)
{
	return atan2(y2 - y1, x2 - x1) * 180 / M_PI;
}

double Math::FastInvSqrt(double value)
{
	double Half = 0.5f * value;
	int i = *(int *)&value;
	i = 0x5f3759df - (i >> 1);// This line hides a LOT of math!
	value = *(float *)&i;
	value = value * (1.5f - Half*value*value);// repeat this statement for a better approximation
	return value;
}
