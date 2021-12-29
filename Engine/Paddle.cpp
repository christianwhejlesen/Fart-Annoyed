#include "Paddle.h"

//Paddle::Paddle(const RectF& in_rect, Color in_color)
//	:
//	rect(in_rect.left - (halfWidth + wingsWidth), in_rect.right + (halfWidth + wingsWidth), in_rect.top - (bottomPad+(halfHeight*2.0f)), in_rect.bottom - (bottomPad + halfHeight)),
//	padColor(in_color)
//{
//}

Paddle::Paddle(const Vec2& in_position, Color in_color)
	:
	position(in_position),
	padColor(in_color)
{
	rect = RectF::FromCenter(Vec2(position.x, position.y - (bottomPad + halfHeight * 2.0f)), halfWidth, halfHeight);
}

void Paddle::Update(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		position.x -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		position.x += speed * dt;
	}

	rect = GetRect();
	
}

void Paddle::WallCollision(const RectF& walls)
{
	const RectF padBounding = GetRect();
	if (padBounding.left - wingsWidth < walls.left)
	{
		position.x += walls.left - padBounding.left + wingsWidth;
	}
	else if (rect.right + wingsWidth > walls.right)
	{
		position.x -= padBounding.right - walls.right + wingsWidth;
	}

	rect = GetRect();
}

bool Paddle::BallCollision(Ball& ball)
{
	if (!coolDown)
	{
		if (rect.IsOverLapping(ball.GetRect()))
		{
			const Vec2 ballPos = ball.GetPosition();
			if (signbit(ball.GetVelocity().x) == signbit((ballPos - position).x))
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
			SetCoolDown(true);
			return true;
		}
	}
	return false;
}


void Paddle::Draw(Graphics& gfx)
{
	gfx.DrawRect(int(rect.left - wingsWidth), int(rect.top), int(rect.right + wingsWidth), int(rect.bottom), wingColor);
	gfx.DrawRect(rect, padColor);
}

RectF Paddle::GetRect()
{
	return RectF::FromCenter(position, halfWidth, halfHeight);
}

void Paddle::SetCoolDown(bool setValue)
{
	coolDown = setValue;
}
