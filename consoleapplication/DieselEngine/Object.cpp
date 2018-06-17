#include"Object.h"

#include"Scene.h"
#include"System.h"
#include"Math.h"
#include"Camera.h"

void Object::Background()
{
	if (isRelease) {
		parent->objectMap.erase(parent->objectIterator++);
		delete this;
		return;
	}
	else
		++parent->objectIterator;

	previousX = x;
	previousY = y;

	Draw();


	if (!parent->isPause && GetSystem.isWindowActivate)
	{
		if (speed != 0)
		{
			x += GetMath.Cos(direction)*speed;
			y += GetMath.Sin(direction)*speed;
		}
		Step();
	}
}

void Object::ReleaseObject()
{
	Release();
	
	isRelease = true;
}


void Object::DrawTexturePart(Texture *texture, double x, double y, int left, int top, int width, int height, int r, int g, int b)
{
	SDL_Rect src, dst;
	SDL_Point point;

	point.x = texture->centerX*width*texture->scaleX ;
	point.y = texture->centerY*height*texture->scaleY;

	src.x = left;
	src.y = top;
	src.w = width;
	src.h = height;
	
	dst.x = x - point.x;
	dst.y = y - point.y;
	dst.w = src.w * texture->scaleX;
	dst.h = src.h * texture->scaleY;

	SDL_SetTextureColorMod(texture->texture, r,g,b);
	SDL_SetTextureBlendMode(texture->texture, (SDL_BlendMode)texture->blendmode);
	SDL_SetTextureAlphaMod(texture->texture, texture->alpha*255.0);

	SDL_RenderCopyEx(GetSystem.renderer, texture->texture, &src, &dst, texture->angle, &point, SDL_FLIP_NONE);
}

void Object::DrawTexturePart(Texture *texture, double x, double y, int left, int top, int width, int height)
{
	DrawTexturePart(texture, x, y, left, top, width, height, r,g,b);
}

void Object::DrawTexture(Texture *texture, double x, double y, int r, int g, int b)
{
	DrawTexturePart(texture, x, y,0,0,texture->width,texture->height,r,g,b);
}

void Object::DrawTexture(Texture *texture, double x, double y)
{
	DrawTexture(texture, x, y,r,g,b);
}

void Object::DrawTexture(Texture *texture)
{
	DrawTexture(texture, x, y);
}

void Object::DrawLine(double x1, double y1, double x2, double y2)
{
	SDL_RenderDrawLine(GetSystem.renderer, x1, y1, x2, y2);
}

int Object::DrawNumber(Texture *texture, int number, int space, double x, double y, int align)
{
	int numlen = strlen(std::to_string(number).data());

	int w = texture->width / 10;
	int h = texture->height;

	double skv_m = w + space;//(space*(numlen - 1)) - (space*(numlen / 2));

	int skv_k = 1;

	for (int i = numlen - 1; i >= 0; i--){
		int div = floor(number / skv_k);
		div %= 10;
		int a;
		switch (align) {
		case 0: a = i*skv_m - 1; break;
		case 1: a = i*skv_m - ((numlen) / 2)*skv_m + (1 - numlen % 2)*skv_m / 2 - 1; break;
		case 2: a = i*skv_m - (numlen - 1)*skv_m - 1; break;
		}

		DrawTexturePart(texture, x + a, y, div*w, 0, w, h, 255, 255, 255);
		skv_k *= 10;
	}
	return numlen;
}