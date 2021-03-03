#pragma once
#include "Colors.h"

/*
This class prepares a buffer and loads data into newly created buffer
*/

class Surface
{
public:
	Surface(int width, int height);
	Surface(const Surface&);
	Surface& operator=(const Surface&);
	~Surface();
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
private:
	Color* pPixels = nullptr;
	int width;
	int height;
};