#include "Engine.h"

Engine::Engine(Window& wnd)
{
	Colors = wnd.GetColorBuffer();
}

Engine::~Engine()
{
}

void Engine::Run(Window& wnd)
{
	//Thread sleep to stop burning cycles
	float dt = ft.Go();
	bench += dt;
	std::chrono::duration<float> ThreadSleepTime(FPSMS - bench);
	if (bench < FPSMS)
	{
		//Windows native command to hold thread cycles
		Sleep(DWORD(ThreadSleepTime.count() * 1000.0f));
	}
	else
	{
		bench = 0.0f;
	}
	counter = std::to_string(cX);
	finTitle = winName + counter;
	SetWindowTextA(wnd.GetCustomWindow(), finTitle.c_str());
	cX = 1.0f / ThreadSleepTime.count();


	Update(wnd);
	ComposeFrame();
}

void Engine::Update(Window& wnd)
{
	//Test
	/*if (wnd.kbd.KeyIsPressed('W'))
	{
		OutputDebugStringA("W is down\n");
	}
	*/
	x = wnd.mouse.GetPosX();
	y = wnd.mouse.GetPosY();
}

void Engine::ComposeFrame()
{
	//gfx.FillScreenFast(Colors,255, 0, 0);
	gfx.ClearScreenSuperFast(Colors);
	//gfx.DrawPixel(Colors, 100, 100, 255, 0, 0);
	//Test
	//Test
	for (int sy = 1; sy < 20; sy++)
	{
		for (int sx = 1; sx < 20; sx++)
		{
			gfx.DrawPixel(Colors, sx + x, sy + y, 255, 0, 0);
		}
	}
}


