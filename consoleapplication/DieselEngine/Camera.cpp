#include"Camera.h"

#include"System.h"
#include<stdio.h>

Camera *Camera::camera = 0;

Camera &Camera::GetInstance()
{
	if (camera == NULL) camera = new Camera();
	return *camera;
}

void Camera::Update()
{
	src.x = 0;
	src.y = 0;
	src.w = GetSystem.width;
	src.h = GetSystem.height;
	
	center.x = centerX * src.w * zoom;
	center.y = centerY * src.h * zoom;

	dst.x = x - (src.w*zoom - src.w)/2;
	dst.y = y - (src.h*zoom - src.h)/2;
	dst.w = src.w * zoom;
	dst.h = src.h * zoom;
}

void Camera::Release()
{
	delete this;
}