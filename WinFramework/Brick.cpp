#include "Brick.h"

Brick::Brick(const RectF& rect_in, unsigned char r, unsigned char g, unsigned char b)
	:
	rect(rect_in),
	R(r),
	G(g),
	B(b)
{
}

void Brick::Draw(Graphics& gfx, int* Colors)
{
	if (!destroyed)
	{
		for (int sy = (int)(rect.top + padding); sy < (int)(rect.bottom - padding); sy++)
		{
			for (int sx = (int)(rect.left + padding); sx < (int)(rect.right - padding); sx++)
			{
				gfx.DrawPixel(Colors, sx, sy, R, G, B);
			}
		}
	}
}

bool Brick::DoBallCollision(Ball& ball)
{
	if (!destroyed && rect.IsOverlappingWith(ball.GetRect()))
	{
		const Vec2 ballPos = ball.GetPosition();
		if (ballPos.x >= rect.left && ballPos.x <= rect.right)
		{
			ball.ReboundY();
		}
		else
		{
			ball.ReboundX();
		}
		destroyed = true;
		return true;
	}
	return false;
}
