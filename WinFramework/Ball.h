#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "RectF.h"

class Ball
{
public:
	Ball() = default;
	Ball(const Vec2& pos_in, const Vec2& vel_in);
	~Ball();
	bool DoWallCollision(const RectF& walls);
	void ReboundX();
	void ReboundY();
	RectF GetRect() const;
	RectF MakeRect() const;
	void Draw(Graphics& gfx, int* Colors);
	void Update(float dt);
	Vec2 GetVelocity() const;
	Vec2 GetPosition() const;
	void SetVelocity(Vec2 in);
	void SetPos(Vec2 in);

private:
	static constexpr float radius = 5.0f;
	Vec2 pos;
	Vec2 vel;
};