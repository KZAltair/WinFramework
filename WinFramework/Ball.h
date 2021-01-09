#pragma once
#include "Graphics.h"

class Ball
{
public:
	Ball(int radius, float x, float y);
	~Ball();

	void DrawBall(Graphics& gfx, int* Colors);
	void Update(float dt);

private:
	float x;
	float y;
	int radius;
	float speed = 50.0f;
};