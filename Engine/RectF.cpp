#include "RectF.h"

RectF::RectF(float in_left, float in_top, float in_right, float in_bottom)
	:
	left(in_left),
	right(in_right),
	top(in_top),
	bottom(in_bottom)
{
}

RectF::RectF(const Vec2& topleft, const Vec2& bottomright)
{
	RectF(topleft.x, topleft.y, bottomright.x, bottomright.y);
}

RectF::RectF(const Vec2& topleft, float width, float height)
{
	RectF(topleft.x, topleft.y, topleft.x + width, topleft.y + height);
}

bool RectF::IsOverLapping(const RectF& other) const
{
	return right > other.left && left < other.left&& top<other.bottom&& bottom>other.top;
}
