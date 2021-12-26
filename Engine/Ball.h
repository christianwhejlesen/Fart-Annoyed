#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Ball
{
public:
	Ball(const Vec2& in_position, const Vec2& in_velocity);
	void Draw(Graphics& gfx) const;
	void Update(float fElapsedTime);
	bool WallBounce(const RectF& walls);
	void BounceX();
	void BounceY();
	RectF GetRect() const;

private:
	Vec2 position;
	Vec2 velocity;
	static constexpr float radius = 7.0f;
};

