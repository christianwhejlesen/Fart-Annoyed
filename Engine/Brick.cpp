#include "Brick.h"
#include <assert.h>

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
		gfx.DrawRect(rect.GetExpanded(-fPadding), color);
	}
}

RectF Brick::GetRect()
{
	return rect;
}

bool Brick::HasCollided(Ball& ball)
{
	return !destroyed && rect.IsOverLapping(ball.GetRect());
}

void Brick::Destroy(Ball& ball)
{
	assert(HasCollided(ball));
	const Vec2 ballPos = ball.GetPosition();
	if (signbit(ball.GetVelocity().x) == signbit((ballPos-GetCenter()).x))
	{
		ball.BounceY();
	}
	else if (ballPos.x >= rect.left && ballPos.x <= rect.right)
	{
		ball.BounceY();
	}
	else
	{
		ball.BounceX();
	}

	destroyed = true;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}



