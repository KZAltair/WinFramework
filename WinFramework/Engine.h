#pragma once
#include "Window.h"
#include "Graphics.h"
#include "Timer.h"
#include <string>
//TODO: remake this from sleep to thread
#include <thread>

class Engine
{
public:
	Engine(class Window& wnd);
	Engine(const Engine&) = delete;
	Engine operator=(const Engine&) = delete;
	~Engine();

	void Run(class Window& wnd);
private:
	void ComposeFrame();
	void Update(class Window& wnd);
private:
	Graphics gfx;
	int* Colors;
	Timer ft;

private:
	const float FPSMS = 1.0f / 30.0f;
	float bench = 0.0f;
	std::string winName = "Windows Framework ";
	std::string counter;
	std::string finTitle;
	float cX = 0;

private:
	//Game stuff here
	int x = 10;
	int y = 10;
};