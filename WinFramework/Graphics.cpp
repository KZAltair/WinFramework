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

void Graphics::ClearScreenSuperFast(int* Colors)
{
	std::memset(Colors, 0, 800 * 600 * 4);
}

void Graphics::DrawPixel(int* Colors, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
	assert(x > 0);
	assert(x < 800 - 1);
	assert(y > 0);
	assert(y < 600 - 1);
	Colors[y * 800 + x] = (r << 16) | (g << 8) | b;
}

