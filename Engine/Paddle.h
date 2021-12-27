#pragma once

#include "Vec2.h"
#include "Ball.h"
#include "Colors.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle
{
public:
	Paddle() = default;
	Paddle(const Vec2& in_position, Color in_color);
	//Paddle(const RectF& in_rect, Color in_color);
	void Update(Keyboard& kbd, float dt);
	void WallCollision(const RectF& walls);
	bool BallCollision(Ball& ball) const;
	void Draw(Graphics& gfx);
	RectF GetRect();


private:
	static constexpr float halfWidth = 40.0f;
	static constexpr float halfHeight = 10.0f;
	float wingsWidth = 10.0f;
	float bottomPad = 15.0f;
	Color padColor = Colors::LightGray;
	Color wingColor = Colors::Red;
	static constexpr float speed = 400.0f;
	RectF rect;
	Vec2 position;
};


