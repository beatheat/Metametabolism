#ifndef _LABEL_H_
#define _LABEL_H_

#include<SDL.h>
#include<SDL_ttf.h>
#include<string>

#include"ResourceManager.h"

typedef struct _Size{
	int width, height;
}Size;

class Label
{
public:
	TTF_Font *font;
	std::wstring text;
	SDL_Texture *texture;
	double x, y, z; 
	float centerX = 0.5, centerY = 0.5;
	double scaleX = 1, scaleY = 1;
	float alpha = 1;
	double angle = 0;
	int width, height;
	BlendMode blendmode = BLENDMODE_BLEND;

	bool isFirst = true;

	bool isShadow = false;
	double shadowAngle = 0;	

	int r = 0, g = 0, b = 0;
	SDL_Color shadowColor;
public:
	static Label *Create(TTF_Font *font, double x, double y);

	static const Size &CalcText(TTF_Font *font, const std::wstring &text);

	void SetText(const std::wstring &text);
	/*만약 글이 박스를 넘어서면 -1 반환, 평소엔 0 반환*/
	int SetTextInBox(const std::wstring &text, int width, int height);

	void SetColor(int r, int g, int b);

	void SetShadow(double angle, int r, int g, int b);

	void Draw();
	void Release();

private:
	void DrawText(SDL_Texture *texture, double x, double y, double z, double scaleX,double scaleY, float centerX, float centerY, double angle, float alpha, BlendMode blendmode,int r, int g, int b);
	static Uint16 *WCharToUint16(std::wstring text);
};

#endif