#include "Brick.h"
#include <assert.h>
#include <cmath>
#include <algorithm>

Brick::Brick(const RectF& rect_in, unsigned char r, unsigned char g, unsigned char b)
	:
	rect(rect_in),
	destroyed(false),
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

bool Brick::CheckBallCollision(const Ball& ball) const
{
	return !destroyed && rect.IsOverlappingWith(ball.GetRect());
}

void Brick::DoBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));
	const Vec2 ballPos = ball.GetPosition();
	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.ReboundY();
	}
	else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	destroyed = true;
}

void Brick::DoTraceCollisionTest(Ball& ball, const RectF& target, Vec2& contact_point,
	Vec2& contact_normal, float& contact_time, float ElapsedTime)
{
	if (!destroyed)
	{
		if (cCollider.DynamicRectVsRect(ball.GetVelocity(), ball.MakeRect(), target, contact_point, contact_normal,
			contact_time, ElapsedTime))
		{
			Vec2 newVel = ball.GetVelocity();
			Vec2 ballVel = ball.GetVelocity();
			ballVel.Normalize();
			ballVel += contact_normal * 2.0f;
			float len = newVel.GetLength();
			ballVel = ballVel.Normalize() * len;
			ball.SetVelocity(ballVel);
			destroyed = true;
		}
	}
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}

RectF Brick::GetOriginalRect() const
{
	return rect;
}
