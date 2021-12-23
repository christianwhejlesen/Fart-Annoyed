#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& in_position, const Vec2& in_velocity)
	:
	position(in_position),
	velocity(in_velocity)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(position, gfx);
}
