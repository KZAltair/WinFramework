#include "Graphics.h"
#include <iostream>
#include <assert.h>

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
}

void Graphics::FillScreenFast(int* Colors, unsigned char r, unsigned char g, unsigned char b)
{
	for (int* i = Colors, *end = &Colors[800 * 600]; i < end; i++)
	{
		*i = (r << 16) | (g << 8) | b;
	}
}

void Graphics::FillScreenFast(int* Colors, Color c)
{
	for (int* i = Colors, *end = &Colors[800 * 600]; i < end; i++)
	{
		*i = c.dword;
	}
}

void Graphics::ClearScreenSuperFast(int* Colors)
{
	std::memset(Colors, 0, 800 * 600 * 4);
}

void Graphics::DrawPixel(int* Colors, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
	assert(x >= 0);
	assert(x <= 800);
	assert(y >= 0);
	assert(y <= 600);
	Colors[y * 800 + x] = (r << 16) | (g << 8) | b;
}

void Graphics::DrawPixel(int* in_buffer, int x, int y, Color c)
{
	assert(x >= 0);
	assert(x < 800);
	assert(y >= 0);
	assert(y < 600);
	in_buffer[y * 800 + x] = c.dword;
}

void Graphics::DrawLine(int* Colors, Vec2 p0, Vec2 p1, unsigned char r, unsigned char g, unsigned char b)
{
	float m = 0.0f;

	if (p1.x != p0.x)
	{
		m = (p1.y - p0.y) / (p1.x - p0.x);
	}

	if (p1.x != p0.x && std::abs(m) <= 1.0f)
	{
		if (p0.x > p1.x)
		{
			std::swap(p0, p1);
		}

		const float h = p0.y - m * p0.x;

		for (int x = (int)p0.x; x < (int)p1.x; x++)
		{
			const float y = m * (float)x + h;
			DrawPixel(Colors, x, (int)y, r, g, b);
		}
	}
	else
	{
		if (p0.y > p1.y)
		{
			std::swap(p0, p1);
		}
		const float w = (p1.x - p0.x) / (p1.y - p0.y);
		const float p = p0.x - w * p0.y;

		for (int y = (int)p0.y; y < (int)p1.y; y++)
		{
			const float x = w * (float)y + p;
			DrawPixel(Colors, (int)x, y, r, g, b);
		}
	}

	
	
}

void Graphics::DrawRect(int* Colors, const RectF& rect_in, unsigned char r, unsigned char g, unsigned char b)
{
	for (int sy = (int)rect_in.top; sy < (int)rect_in.bottom; sy++)
	{
		for (int sx = (int)rect_in.left; sx < (int)rect_in.right; sx++)
		{
			DrawPixel(Colors, sx, sy, r, g, b);
		}
	}
}

void Graphics::DrawSpriteNonChroma(int* in_buffer, int x, int y, const Surface& s)
{
	DrawSpriteNonChroma(in_buffer, x, y, s.GetRect(), s);
}

void Graphics::DrawSpriteNonChroma(int* in_buffer, int x, int y, RectF& srcRect, const Surface& s)
{
	DrawSpriteNonChroma(in_buffer, x, y, srcRect, RectF(0.0f, 800.0f, 0.0f, 600.0f), s);
}

void Graphics::DrawSpriteNonChroma(int* in_buffer, int x, int y, RectF& srcRect, const RectF& clip, const Surface& s)
{
	assert(srcRect.left >= 0);
	assert(srcRect.left <= s.GetWidth());
	assert(srcRect.top >= 0);
	assert(srcRect.bottom <= s.GetHeight());
	if ((float)x < clip.left)
	{
		srcRect.left += clip.left - (float)x;
		x = (int)clip.left;
	}
	if ((float)y < clip.top)
	{
		srcRect.top += clip.top - (float)y;
		y = (int)clip.top;
	}
	if ((float)x + srcRect.GetWidth() > clip.right)
	{
		srcRect.right -= (float)x + srcRect.GetWidth() - clip.right;
	}
	if ((float)y + srcRect.GetHeight() > clip.bottom)
	{
		srcRect.bottom -= (float)y + srcRect.GetHeight() - clip.bottom;
	}
	for (int sy = (int)srcRect.top; sy < (int)srcRect.bottom; sy++)
	{
		for (int sx = (int)srcRect.left; sx < (int)srcRect.right; sx++)
		{
			DrawPixel(in_buffer, x + sx - (int)srcRect.left, y + sy - (int)srcRect.top, s.GetPixel(sx, sy));
		}
	}
}

void Graphics::DrawSprite(int* in_buffer, int x, int y, const Surface& s, Color chroma)
{
	DrawSprite(in_buffer, x, y, s.GetRect(), s, chroma);
}

void Graphics::DrawSprite(int* in_buffer, int x, int y, RectF& srcRect, const Surface& s, Color chroma)
{
	DrawSprite(in_buffer, x, y, srcRect, RectF(0.0f, 800.0f, 0.0f, 600.0f), s, chroma);
}

void Graphics::DrawSprite(int* in_buffer, int x, int y, RectF& srcRect, const RectF& clip, const Surface& s, Color chroma)
{
	assert(srcRect.left >= 0);
	assert(srcRect.left <= s.GetWidth());
	assert(srcRect.top >= 0);
	assert(srcRect.bottom <= s.GetHeight());
	if ((float)x < clip.left)
	{
		srcRect.left += clip.left - (float)x;
		x = (int)clip.left;
	}
	if ((float)y < clip.top)
	{
		srcRect.top += clip.top - (float)y;
		y = (int)clip.top;
	}
	if ((float)x + srcRect.GetWidth() > clip.right)
	{
		srcRect.right -= (float)x + srcRect.GetWidth() - clip.right;
	}
	if ((float)y + srcRect.GetHeight() > clip.bottom)
	{
		srcRect.bottom -= (float)y + srcRect.GetHeight() - clip.bottom;
	}
	for (int sy = (int)srcRect.top; sy < (int)srcRect.bottom; sy++)
	{
		for (int sx = (int)srcRect.left; sx < (int)srcRect.right; sx++)
		{
			const Color srcPixel = s.GetPixel(sx, sy);
			if (srcPixel != chroma)
			{
				DrawPixel(in_buffer, x + sx - (int)srcRect.left, y + sy - (int)srcRect.top, srcPixel);
			}
			
		}
	}
}

