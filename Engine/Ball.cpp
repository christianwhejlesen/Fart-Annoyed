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

void Ball::Update(float fElapsedTime)
{
	position += velocity * fElapsedTime;
}

bool Ball::WallBounce(const RectF& wall)
{
	bool collided = false;
	const RectF ballBounding = GetRect();
	if (ballBounding.left < wall.left)
	{
		position.x += wall.left - ballBounding.left;
		BounceX();
		collided = true;
	}
	else if (ballBounding.right > wall.right)
	{
		position.x -= ballBounding.right - wall.right;
		BounceX();
		collided = true;
	}
	if (ballBounding.top < wall.top)
	{
		position.y += wall.top - ballBounding.top;
		BounceY();
		collided = true;
	}
	else if (ballBounding.bottom > wall.bottom)
	{
		position.y -= ballBounding.bottom - wall.bottom;
		BounceY();
		collided = true;
	}

	return collided;
}


void Ball::BounceX()
{
	velocity.x = -velocity.x;
}

void Ball::BounceY()
{
	velocity.y = -velocity.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(position, radius, radius);
}

Vec2 Ball::GetVelocity() const
{
	return velocity;
}

Vec2 Ball::GetPosition() const
{
	return position;
}

