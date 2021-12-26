#pragma once
#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick(const RectF& in_rect, Color in_color);
	void Draw(Graphics& gfx) const;
	RectF GetRect();
	bool HasCollided(Ball& ball);
	bool IsDestroyed();

private:
	RectF rect;
	Color color;
	bool destroyed = false;
};

