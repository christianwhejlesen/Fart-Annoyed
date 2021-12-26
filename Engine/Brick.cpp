#include "Brick.h"

Brick::Brick(const RectF& in_rect, Color in_color)
	:
	rect(in_rect),
	color(in_color)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed)
	{
		gfx.DrawRect(rect, color);
	}
}

RectF Brick::GetRect()
{
	return rect;
}

bool Brick::HasCollided(Ball& ball)
{
	if (!destroyed && rect.IsOverLapping(ball.GetRect()))
	{
		ball.BounceY();
		destroyed = true;
		return true;
	}
	return false;
}

bool Brick::IsDestroyed()
{
	return destroyed;
}


