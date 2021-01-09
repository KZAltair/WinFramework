#include "Rect.h"

Rect::Rect(int x, int y, int width, int height)
	:
	x(x),
	y(y),
	width(width),
	height(height)
{
}

bool Rect::IsOverlapping(const Rect& other)
{
	if (x < other.x && width > other.width && y < other.y && height > other.height)
	{
		return true;
	}
	return false;
}
