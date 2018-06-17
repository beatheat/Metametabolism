#ifndef _ENGINE_H_
#define _ENGINE_H_

class Engine
{
public:
	Engine(const char *title, int width, int hegith);

private:
	void Release();

public:
	int Run();
};

#endif