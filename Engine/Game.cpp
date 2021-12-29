/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball( Vec2{400.0f,300.0f}, Vec2{300.0f,300.0f}),
	walls(0.0f,float(gfx.ScreenWidth), 0.0f, float(gfx.ScreenHeight)),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav"),
//	brick(RectF(400.0f,520.0f,200.0f,220.0f),Colors::Green),
	pad(padPosition, Colors::White)

{
	const Color col[nColors] = { Colors::Red, Colors::Blue, Colors::Green, Colors::Yellow };

	for (int rows = 0; rows < nBrickRows; rows++)
	{
		for (int columns = 0; columns < nBrickColumns; columns++)
		{
			bricks[(rows * nBrickColumns + columns)] = Brick(RectF(Vec2((float(columns)* fBrickWidth) + fOffsetX, (float(rows)* fBrickHeight) + fOffsetY), fBrickWidth, fBrickHeight), col[rows % nColors]);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();
	while (elapsedTime>0.0f)
	{
		const float dt = std::min(0.0025f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float fElapsedTime)
{
	//float fElapsedTime = ft.Mark();

	pad.Update(wnd.kbd, fElapsedTime);
	pad.WallCollision(walls);

	ball.Update(fElapsedTime);

	if (ball.WallBounce(walls))
	{
		pad.SetCoolDown(false);
		//soundPad.Play();
	}

	bool collisionHappend = false;
	float fCurColDistSq;
	int nCurColIndex;

	for (int i = 0; i < nBricks; i++)
	{
		if (bricks[i].HasCollided(ball))
		{
			const float fNexColDistSq = (ball.GetPosition() - bricks[i].GetCenter()).GetLengthSq();
			if (collisionHappend)
			{
				if (fNexColDistSq < fCurColDistSq)
				{
					fCurColDistSq = fNexColDistSq;
					nCurColIndex = i;
				}
			}
			else
			{
				collisionHappend = true;
				fCurColDistSq = fNexColDistSq;
				nCurColIndex = i;
			}
		}
	}

	if (collisionHappend)
	{
		soundBrick.Play();
		nScore++;
		bricks[nCurColIndex].Destroy(ball);
		pad.SetCoolDown(false);
	}

	if (pad.BallCollision(ball))
	{
		soundPad.Play();
	}
}

void Game::ComposeFrame()
{
	for (const Brick& b : bricks)
	{
		b.Draw(gfx);
	}
	pad.Draw(gfx);
	ball.Draw(gfx);
}
