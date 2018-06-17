#include"Graph.h"

#include"Data.h"
#include<stdio.h>

void Graph::Initialize()
{
	std::string resource;
	if (tag == "oxygen") resource = "oxygraph";
	if (tag == "heart") resource = "heartgraph";
	if (tag == "sugar") resource = "sugargraph";
	if (tag == "chole") resource = "cholegraph";
	tBox = GetResourceManager.GetTexture(resource);
	lines.clear();
}

void Graph::Step()
{
	lines.clear();
	if (tag == "oxygen")
	{
		int i = 0;
		double last = 0;
		for (std::list<int>::iterator iter = Data::oxyinlungs.begin(); iter != Data::oxyinlungs.end();)
		{
			Line line;
			line.nx = i * 3;
			line.ny = *iter++ * (-1);
			line.ex = ++i * 3;
			if (iter == Data::oxyinlungs.end()){
				line.ey = last;
			}
			else last = line.ey = *(iter) * (-1);
			lines.push_back(line);
		}
	}

	if (tag == "heart")
	{
		int i = 0;
		double last = 0;
		for (std::list<int>::iterator iter = Data::heartbeat.begin(); iter != Data::heartbeat.end();)
		{
			Line line;
			line.nx = i * 3;
			line.ny = *iter++ * (-1);
			line.ex = ++i * 3;
			if (iter == Data::heartbeat.end()){
				line.ey = last;
			}
			else last = line.ey = *(iter)* (-1);
			lines.push_back(line);
		}
	}

	if (tag == "sugar")
	{
		int i = 0;
		double last = 0;
		for (std::list<int>::iterator iter = Data::bloodsugar.begin(); iter != Data::bloodsugar.end();)
		{
			Line line;
			line.nx = i * 3;
			line.ny = *iter++ * (-1);
			line.ex = ++i * 3;
			if (iter == Data::bloodsugar.end()){
				line.ey = last;
			}
			else last = line.ey = *(iter)* (-1);
			lines.push_back(line);
		}
	}

	if (tag == "chole")
	{
		int i = 0;
		double last = 0;
		for (std::list<int>::iterator iter = Data::cholesterol.begin(); iter != Data::cholesterol.end();)
		{
			Line line;
			line.nx = i * 3;
			line.ny = *iter++ * (-1);
			line.ex = ++i * 3;
			if (iter == Data::cholesterol.end()){
				line.ey = last;
			}
			else last = line.ey = *(iter)* (-1);
			lines.push_back(line);
		}
	}
}

void Graph::Draw()
{
	DrawTexture(tBox,x,y);
	SDL_SetRenderDrawColor(GetSystem.renderer, 0, 0, 0, 255);
	for (std::list<Line>::iterator iter = lines.begin(); iter != lines.end();iter++)
	{
		DrawLine(iter->ex - 50 + x, iter->ey + y + 50, iter->nx - 50 + x, iter->ny + y + 50);
	}
}

void Graph::Release()
{
	
}