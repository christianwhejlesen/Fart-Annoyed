#include "RectF.h"

RectF::RectF(float in_left, float in_right, float in_top, float in_bottom)
	:
	left(in_left),
	top(in_top),
	right(in_right),
	bottom(in_bottom)
{
}

RectF::RectF(const Vec2& topleft, const Vec2& bottomright)
	:
	RectF(topleft.x, bottomright.x, topleft.y, bottomright.y)
{
}

RectF::RectF(const Vec2& topleft, float width, float height)
	:
	RectF(topleft, Vec2{ topleft.x + width, topleft.y + height })
{
}

bool RectF::IsOverLapping(const RectF& other) const
{
	return right > other.left && left < other.right && top < other.bottom && bottom > other.top;
}

float RectF::DistanceFromCenter(const Vec2& other) const
{
	return other.GetLengthSq();
}




RectF RectF::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center-half,center+half);
}

RectF RectF::GetExpanded(float offset) const
{
	return RectF(left - offset, right + offset, top - offset, bottom + offset);
}

Vec2 RectF::GetCenter() const
{
	return Vec2((left + right) / 2.0f, (top + bottom) / 2.0f);
}
