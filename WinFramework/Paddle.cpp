#include "Paddle.h"
#include <cmath>

Paddle::Paddle(const Vec2& pos_in, int width, int height, unsigned char r, unsigned char g, unsigned char b)
	:
	pos(pos_in),
	width(width),
	height(height),
	R(r),
	G(g),
	B(b)
{
	vel = { 0.0, 0.0f };
	speed = 0.0f;
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
	Vec2 oldPos = pos;
	pos.x = (float)(mouse.GetPosX());
	speed = (pos - oldPos).GetLength();
	vel = (pos - oldPos).Normalize();
}

bool Paddle::DoBallCollision(Ball& ball)
{
	const RectF rect = GetRect();
	if (rect.IsOverlappingWith(ball.GetRect()))
	{
		const Vec2 ballPos = ball.GetPosition();
		if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - rect.GetCenter()).x))
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

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, (float)(width / 2), (float)(height /2));
}

void Paddle::DoTraceCollisionTest(Ball& ball, const RectF& target, Vec2& contact_point,
	Vec2& contact_normal, float& contact_time, float ElapsedTime)
{
	if (cCollider.DynamicRectVsRect(ball.GetVelocity(), ball.MakeRect(), target, contact_point, contact_normal,
			contact_time, ElapsedTime))
	{
			Vec2 newVel = ball.GetVelocity();
			Vec2 ballVel = ball.GetVelocity();
			ballVel.Normalize();
			ballVel += (contact_normal * 2.0f) + vel;
			len = newVel.GetLength() + speed;
			len = std::min(len, maxSpeed);
			ballVel = (ballVel.Normalize() * len);
			ball.SetVelocity(ballVel);
	}
}

float Paddle::GetSpeed() const
{
	return len;
}

Vec2 Paddle::GetVelocity() const
{
	return vel;
}
