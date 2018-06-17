#include"Label.h"

#include "ResourceManager.h"
#include "Math.h"
#include "System.h"
#include <wchar.h>

Label *Label::Create(TTF_Font *font, double x, double y)
{
	if (font == NULL) {
		printf("Error: no font in label");
		return NULL;
	}
	Label *label = new Label;
	label->font = font;
	label->x = x;
	label->y = y;

	return label;
}
		
const Size &Label::CalcText(TTF_Font *font, const std::wstring &text)
{
	Size size;
	Uint16 *utext = WCharToUint16(text);
	TTF_SizeUNICODE(font, utext, &size.width, &size.height);
	delete[] utext;
	return size;
}

void Label::SetText(const std::wstring &text)
{
	if (!isFirst) {
		SDL_DestroyTexture(texture);
		texture = NULL;
	}

	this->text = text;
	Uint16 *utext = WCharToUint16(text);
	SDL_Color color = { 255,255,255,255 };
	SDL_Surface *s_t = TTF_RenderUNICODE_Solid(font, utext, color);
	texture = SDL_CreateTextureFromSurface(GetSystem.renderer, s_t);
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	SDL_FreeSurface(s_t);
	delete[] utext;

	isFirst = false;
}

int Label::SetTextInBox(const std::wstring &text, int width, int height)
{
	if (!isFirst) {
		SDL_DestroyTexture(texture);
		texture = 0;
	}

	this->text = text;

	Uint16 *utext = WCharToUint16(text);
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface *s_t = TTF_RenderUNICODE_Blended_Wrapped(font, utext, color,width);
	SDL_Texture *tText = SDL_CreateTextureFromSurface(GetSystem.renderer, s_t);
	SDL_Texture *buffer = SDL_CreateTexture(GetSystem.renderer, SDL_GetWindowPixelFormat(GetSystem.window) , SDL_TEXTUREACCESS_TARGET, width, height);
	
	SDL_SetRenderTarget(GetSystem.renderer, buffer);
	DrawText(tText, width/2,height/2,z,scaleX,scaleY,centerX,centerY,angle,alpha,blendmode, 255, 255, 255);
	SDL_SetRenderTarget(GetSystem.renderer, NULL);
	texture = tText;
	SDL_QueryTexture(texture, NULL, NULL, &this->width, &this->height);

	SDL_FreeSurface(s_t);
	delete[] utext;
	
	isFirst = false;
	return 0;
}

void Label::SetColor(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void Label::SetShadow(double angle, int r, int g, int b)
{
	isShadow = true;
	shadowAngle = angle;
	shadowColor.r = r;
	shadowColor.g = g;
	shadowColor.b = b;
}

void Label::Draw()
{
	if (isShadow)
		DrawText(texture, x + 4*GetMath.Cos(shadowAngle), y + 4*GetMath.Sin(shadowAngle), z,scaleX,scaleY, centerX, centerY, angle, alpha, blendmode, shadowColor.r, shadowColor.g, shadowColor.b);
	DrawText(texture, x, y, z,scaleX,scaleY, centerX, centerY, angle, alpha, blendmode, r, g, b);
}

void Label::DrawText(SDL_Texture *texture, double x, double y, double z,double scaleX,double scaleY, float centerX, float centerY, double angle, float alpha, BlendMode blendmode, int r, int g, int b)
{
	SDL_Rect src, dst;
	SDL_Point point;

	point.x = centerX*width * scaleX;
	point.y = centerY*height * scaleY;

	src.x = 0;
	src.y = 0;
	src.w = width;
	src.h = height;

	dst.x = x - point.x;
	dst.y = y - point.y;
	dst.w = src.w * scaleX;
	dst.h = src.h * scaleY;

	SDL_SetTextureColorMod(texture, r, g, b);
	SDL_SetTextureBlendMode(texture, (SDL_BlendMode)blendmode);
	SDL_SetTextureAlphaMod(texture, alpha*255.0);

	SDL_RenderCopyEx(GetSystem.renderer, texture, &src, &dst, angle, &point, SDL_FLIP_NONE);
}

void Label::Release()
{
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
	TTF_CloseFont(font);
	delete this;
}

Uint16 *Label::WCharToUint16(std::wstring text)
{
	Uint16 *utext = new Uint16[text.size() + 1];
	for (int i = 0; i < text.size(); i++) utext[i] = text[i];
	utext[text.size()] = 0;
	return utext;
}
