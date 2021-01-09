#include "Ball.h"

Ball::Ball(int radius, int x, int y)
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
	for (int sy = y; sy < y + radius; sy++)
	{
		for (int sx = x; sx < x + radius; sx++)
		{
			gfx.DrawPixel(Colors, sx, sy, 255, 0, 0);
		}
	}
}

void Ball::Update(float dt)
{
}
