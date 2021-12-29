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
	void Destroy(Ball& ball);
	Vec2 GetCenter() const;

private:
	RectF rect;
	Color color;
	bool destroyed = false;
	static constexpr float fPadding = 1.0f;
};

