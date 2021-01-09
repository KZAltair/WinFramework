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
	for (int sy = (int)rect.top; sy < (int)rect.bottom; sy++)
	{
		for (int sx = (int)rect.left; sx < (int)rect.right; sx++)
		{
			gfx.DrawPixel(Colors, sx, sy, R, G, B);
		}
	}
}
