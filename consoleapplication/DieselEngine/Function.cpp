#include "Function.h"

Function *Function::fn = 0;

Function &Function::GetInstance()
{
	if (fn == 0) fn == new Function();
	return *fn;
}

void Function::Release()
{
	delete this;
}

std::string *Function::StringSplit(std::string strTarget, std::string strTok)
{
	int     nCutPos;
	int     nIndex = 0;
	std::string* strResult = new std::string[2];

	while ((nCutPos = strTarget.find_first_of(strTok)) != strTarget.npos)
	{
		if (nCutPos > 0)
		{
			strResult[nIndex++] = strTarget.substr(0, nCutPos);
		}
		strTarget = strTarget.substr(nCutPos + 1);
	}

	if (strTarget.length() > 0)
	{
		strResult[nIndex++] = strTarget.substr(0, nCutPos);
	}

	return strResult;
}

bool Function::CollisionRectToRect(double x1, double y1, int w1, int h1, double x2, double y2, int w2, int h2)
{
	if (x1 + w1 / 2 >= x2 - w2 / 2 && x1 - w1 / 2 <= x2 + w2 / 2
		&& y1 + h1 / 2 >= y2 - h2 / 2 && y1 - h1 / 2 <= y2 + h2 / 2)
	{
		return true;
	}
	return false;
}

bool Function::CollisionRectToCircle(double x1, double y1, int w1, int h1, double x2, double y2, int d)
{
	float left_x = x1 - w1 / 2;
	float right_x = x1 + w1 / 2;
	float up_y = y1 - h1 / 2;
	float down_y = y1 + h1 / 2;

	if ((left_x <= x2 && right_x >= x2) || (up_y <= y2 && down_y >= y2))
	{
		if ((x2 - d / 2 <= right_x) && (x2 + d / 2 >= left_x) && (y2 - d / 2 <= down_y) && (y2 + d / 2 >= up_y))
			return true;
	}
	else
	{
		float len = abs(left_x - x2)*abs(left_x - x2) + abs(up_y - y2)*abs(up_y - y2);//좌상단과 원 중심점
		if (len <= (d / 2)*(d / 2)) return true;
		len = abs(left_x - x2)*abs(left_x - x2) + abs(down_y - y2)*abs(down_y - y2);//좌하단과 원 중심점
		if (len <= (d / 2)*(d / 2)) return true;
		len = abs(right_x - x2)*abs(right_x - x2) + abs(up_y - y2)*abs(up_y - y2);//우상단과 원 중심점
		if (len <= (d / 2)*(d / 2)) return true;
		len = abs(right_x - x2)*abs(right_x - x2) + abs(down_y - y2)*abs(down_y - y2);//우하단과 원 중심점
		if (len <= (d / 2)*(d / 2)) return true;
	}

	return false;
}

bool Function::CollisionCircleToCircle(double x1, double y1, int d1, double x2, double y2, int d2)
{
	float len = abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2);

	if ((d1 / 2 + d2 / 2)*(d1 / 2 + d2 / 2) >= len) {
		return true;
	}
	return false;
}

bool Function::CollisionPointToRect(double x1, double y1, double x2, double y2, int w, int h)
{
	if (x1 >= x2 - w / 2 && x1 <= x2 + w / 2 && y1 >= y2 - h / 2 && y1 <= y2 + h / 2)
		return true;
	return false;
}

bool Function::CollisionPointToCircle(double x1, double y1, double x2, double y2, int d)
{
	float len = abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2);

	if ((d / 2)*(d / 2) >= len)
		return true;
	return false;
}