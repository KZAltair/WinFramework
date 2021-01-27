#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Mouse.h"
#include "Ball.h"

class Paddle
{
public:
	Paddle(const Vec2& pos_in, int width, int height, unsigned char r, unsigned char g, unsigned char b);
	void Draw(Graphics& gfx, int* Colors);
	void Update(Mouse& mouse, float dt);
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const RectF& walls);
private:
	Vec2 pos;
	int width;
	int height;
	unsigned char R;
	unsigned char G;
	unsigned char B;
	static constexpr float speed = 50.0f;
};