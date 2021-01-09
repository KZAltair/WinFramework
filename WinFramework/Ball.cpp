#include "Ball.h"

Ball::Ball(int radius, float x, float y)
	:
	radius(radius),
	x(x),
	y(y)
{
}

Ball::~Ball()
{
}

void Ball::DrawBall(Graphics& gfx, int* Colors)
{
	for (int sy = 0; sy < radius; sy++)
	{
		for (int sx = 0; sx < radius; sx++)
		{
			gfx.DrawPixel(Colors, sx + (int)x, sy + (int)y, 255, 0, 0);
		}
	}
}


void Ball::Update(float dt)
{
	x += speed * dt;
	y += speed * dt;
}

