#pragma once

class Rect
{
public:
	Rect(int x, int y, int width, int height);
	bool IsOverlapping(const Rect& other);
public:
	int x;
	int y;
	int width;
	int height;
};