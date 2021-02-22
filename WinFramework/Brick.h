#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Ball.h"
#include "Collider.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect_in, unsigned char r, unsigned char g, unsigned char b);
	void Draw(Graphics& gfx, int* Colors);
	bool CheckBallCollision(const Ball& ball) const;
	void DoBallCollision(Ball& ball);
	void DoTraceCollisionTest(Ball& ball, const RectF& target, Vec2& contact_point,
		Vec2& contact_normal, float& contact_time, float ElapsedTime);
	Vec2 GetCenter() const;
	RectF GetOriginalRect() const;

private:
	RectF rect;
	static constexpr float padding = 1.0f;
	unsigned char R;
	unsigned char G;
	unsigned char B;
	bool destroyed = true;
	Collider cCollider;
};