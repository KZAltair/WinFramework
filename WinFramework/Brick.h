#pragma once
#include "RectF.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(const RectF& rect_in, unsigned char r, unsigned char g, unsigned char b);
	void Draw(Graphics& gfx, int* Colors);
private:
	RectF rect;
	unsigned char R;
	unsigned char G;
	unsigned char B;
	bool destroyed = false;
};