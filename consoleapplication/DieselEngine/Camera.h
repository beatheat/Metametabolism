#ifndef _CAMERA_H_
#define _CAMERA_H_

#include<SDL.h>

#define GetCamera Camera::GetInstance()

//카메라 2배도 가능하게!!

class Camera
{
private:
	static Camera *camera;
	Camera() : zoom(1.0){};

public:
	double x = 0, y = 0;
	double centerX = 0.5, centerY = 0.5;
	double zoom = 1.0;
	double angle = 0;
	
public:
	friend class Scene;
private:
	SDL_Rect src, dst;
	SDL_Point center;

public:
	void Update();
public:
	static Camera &GetInstance();
	void Release();
};

#endif