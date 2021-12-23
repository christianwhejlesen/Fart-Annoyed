#pragma once
#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float in_left, float in_top, float in_right, float in_bottom);
	RectF(const Vec2& topleft, const Vec2& bottomright);
	RectF(const Vec2& topleft, float width, float height);
	bool IsOverLapping(const RectF& other) const;

public:
	float left;
	float right;
	float top;
	float bottom;
};

