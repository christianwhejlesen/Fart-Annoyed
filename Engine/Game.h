/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Ball.h"
#include "FrameTimer.h"
#include "Sound.h"
#include "Brick.h"
#include "Paddle.h"


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float fElapsedTime);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	static constexpr int nBrickColumns = 16;
	static constexpr int nBrickRows = 7;
	static constexpr float fBrickWidth = 40.0f;
	static constexpr float fBrickHeight = 20.0f;
	const float fOffsetX = float((gfx.ScreenWidth / 2) - (nBrickColumns*fBrickWidth)/2);
	static constexpr float fOffsetY = 50.0f;
	static constexpr int nBricks = nBrickColumns * nBrickRows;
	static constexpr int nColors = 4;
	int nScore = 0;
	Ball ball;
	Brick bricks[nBricks];
	const Vec2 padPosition { float(gfx.ScreenWidth / 2), float(gfx.ScreenHeight - 80) };
	Paddle pad;
	FrameTimer ft;
	RectF walls;
	Sound soundPad;
	Sound soundBrick;
	/********************************/
};