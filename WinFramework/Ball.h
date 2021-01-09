#pragma once
#include "Graphics.h"

class Ball
{
public:
	Ball(int radius, int x, int y);
	~Ball();

	void DrawBall(Graphics& gfx, int* Colors);
	void Update(float dt);

private:
	int x;
	int y;
	int radius;
};