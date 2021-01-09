#include "Ball.h"

Ball::Ball(int radius, float x, float y)
	:
	radius(radius),
	x(x),
	y(y),
	rect(x,y,radius, radius)
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

bool Ball::IsColliding(const Rect& other)
{
	if (rect.IsOverlapping(other))
	{
		if (rect.x < other.x)
		{
			speed *= -1.0f;
		}
		else if (rect.width > other.width)
		{
			speed *= -1.0f;
		}
		else if (rect.y < other.y)
		{
			speed *= -1.0f;
		}
		else if (rect.height > other.height)
		{
			speed *= -1.0f;
		}
		return true;
	}
	return false;
}

void Ball::Update(float dt)
{
	x += speed * dt;
	y += speed * dt;
}

Rect Ball::GetRect() const
{
	return rect;
}
