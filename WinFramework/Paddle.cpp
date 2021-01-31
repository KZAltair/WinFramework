#include "Paddle.h"

Paddle::Paddle(const Vec2& pos_in, int width, int height, unsigned char r, unsigned char g, unsigned char b)
	:
	pos(pos_in),
	width(width),
	height(height),
	R(r),
	G(g),
	B(b)
{
	
}

void Paddle::Draw(Graphics& gfx, int* Colors)
{
	const RectF rect = RectF::FromCenter(pos, (float)(width / 2), (float)(height / 2));
	for (int sy = (int)rect.top; sy < (int)rect.bottom; sy++)
	{
		for (int sx = (int)rect.left; sx < (int)rect.right; sx++)
		{
			gfx.DrawPixel(Colors, sx, sy, R, G, B);
		}
	}
	for (int sy = (int)rect.top; sy < (int)rect.bottom; sy++)
	{
		for (int sx = (int)rect.left + 10; sx < (int)rect.right - 10; sx++)
		{
			gfx.DrawPixel(Colors, sx, sy, 50, 125, 125);
		}
	}
}

void Paddle::Update(Mouse& mouse, float dt)
{
	pos.x = (float)(mouse.GetPosX());
}

bool Paddle::DoBallCollision(Ball& ball)
{
	const RectF rect = RectF::FromCenter(pos, (float)(width / 2), (float)(height / 2));
	if (rect.IsOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::DoWallCollision(const RectF& walls)
{
	const RectF rect = RectF::FromCenter(pos, (float)(width / 2), (float)(height / 2));
	if (rect.IsOverlappingWith(walls))
	{
		if (rect.left < walls.left)
		{
			pos.x += walls.left - rect.left;
		}
		else if (rect.right > walls.right)
		{
			pos.x -= rect.right - walls.right;
		}
	}
}
