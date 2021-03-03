#pragma once
#include "RectF.h"
#include "Colors.h"


class Graphics
{
public:
	Graphics();
	Graphics(const Graphics&) = delete;
	Graphics operator=(const Graphics&) = delete;
	~Graphics();

	void FillScreenFast(int* Colors, unsigned char r, unsigned char g, unsigned char b);
	void FillScreenFast(int* Colors, Color c);
	void ClearScreenSuperFast(int* Colors);
	void DrawPixel(int* Colors, int x, int y, unsigned char r, unsigned char g, unsigned char b);
	void DrawLine(int* Colors, Vec2 p0, Vec2 p1, unsigned char r, unsigned char g, unsigned char b);
	void DrawRect(int* Colors, const RectF& rect_in, unsigned char r, unsigned char g, unsigned char b);
};