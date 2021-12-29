#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF& in_rect, Color in_color);
	void Draw(Graphics& gfx) const;
	RectF GetRect();
	bool HasCollided(Ball& ball);
	float Distance(Ball& ball);
	void IsDestroyed();

private:
	RectF rect;
	Color color;
	bool destroyed = false;
	static constexpr float fPadding = 1.0f;
};

