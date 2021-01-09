#pragma once

class RectF
{
public:
	RectF() = default;
	RectF(float left_in, float right_in, float top_in, float bottom_in);
public:
	float left;
	float top;
	float right;
	float bottom;
};