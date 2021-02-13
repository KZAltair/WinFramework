#include "Ball.h"

Ball::Ball(const Vec2& pos_in, const Vec2& vel_in)
	:
	pos(pos_in),
	vel(vel_in)
{
}

Ball::~Ball()
{
}

bool Ball::DoWallCollision(const RectF& walls)
{
	bool collided = false;
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
		ReboundX();
		collided = true;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		ReboundX();
		collided = true;
	}
	if (rect.top < walls.top)
	{
		pos.y += walls.top - rect.top;
		ReboundY();
		collided = true;
	}
	else if (rect.bottom > walls.bottom)
	{
		pos.y -= rect.bottom - walls.bottom;
		ReboundY();
		collided = true;
	}
	return collided;
}

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(pos, radius, radius);
}

RectF Ball::MakeRect() const
{
	return RectF(pos.x - radius, pos.x + radius, pos.y - radius, pos.y + radius);
}

void Ball::Draw(Graphics& gfx, int* Colors)
{
	const RectF rect = GetRect();
	for (int sy = (int)rect.top; sy < (int)rect.bottom; sy++)
	{
		for (int sx = (int)rect.left; sx < (int)rect.right; sx++)
		{
			gfx.DrawPixel(Colors, sx, sy, 255, 0, 0);
		}
	}
}


void Ball::Update(float dt)
{
	pos += vel * dt;
}

Vec2 Ball::GetVelocity() const
{
	return vel;
}

Vec2 Ball::GetPosition() const
{
	return pos;
}

void Ball::SetVelocity(Vec2 in)
{
	vel = in;
}

void Ball::SetPos(Vec2 in)
{
	pos = in;
}

