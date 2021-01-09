#pragma once
#include "Graphics.h"
#include "Rect.h"

class Ball
{
public:
	Ball(int radius, float x, float y);
	~Ball();

	void DrawBall(Graphics& gfx, int* Colors);
	bool IsColliding(const Rect& other);
	void Update(float dt);
	Rect GetRect() const;

private:
	float x;
	float y;
	int radius;
	Rect rect;
	float speed = 50.0f;
};