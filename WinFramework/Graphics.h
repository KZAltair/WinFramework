#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Surface.h"


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
	void DrawPixel(int* in_buffer, int x, int y, Color c);
	void DrawLine(int* Colors, Vec2 p0, Vec2 p1, unsigned char r, unsigned char g, unsigned char b);
	void DrawRect(int* Colors, const RectF& rect_in, unsigned char r, unsigned char g, unsigned char b);

	void DrawSpriteNonChroma(int* in_buffer, int x, int y, const Surface& s);
	void DrawSpriteNonChroma(int* in_buffer, int x, int y, RectF& srcRect, const Surface& s);
	void DrawSpriteNonChroma(int* in_buffer, int x, int y, RectF& srcRect, const RectF& clip, const Surface& s);
	void DrawSprite(int* in_buffer, int x, int y, const Surface& s, Color chroma = Colors::Magenta);
	void DrawSprite(int* in_buffer, int x, int y, RectF& srcRect, const Surface& s, Color chroma = Colors::Magenta);
	void DrawSprite(int* in_buffer, int x, int y, RectF& srcRect, const RectF& clip, const Surface& s, Color chroma = Colors::Magenta);
};