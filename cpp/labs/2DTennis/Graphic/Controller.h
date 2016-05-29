#pragma once
#include "PhysicEngine.h"
#include "GraphicEngine.h"
#include "Ball.h"
#include "Player.h"
#include "Computer.h"
#include <windows.h>


namespace Graphics
{
	class Controller
	{
	private:
		static PhysicEngine* T_engine;
		static GraphicEngine* T_graphics;
		static int T_direction;
		static int T_motion;
		static unsigned int T_force;
		static unsigned int T_delta;
		static bool T_shoot;
		static bool T_computerShoot;
		static Player* T_player1;
		static Computer* T_player2;
		static Ball* T_ball;
		static int T_diff;
		static int T_field;
		static int T_playerPoints;
		static int T_playerGames;
		static int T_compPoints;
		static int T_compGames;
	public:
		Controller();
		static void SetEngine(PhysicEngine* engine);
		static void SetGraphics(GraphicEngine* engine);
		static GraphicEngine* GetGraphics();
		~Controller(void);
		static void incDelta();
		static void decDelta();
		static unsigned int getDelta();
		static void setDelta(unsigned int delta);
		static bool started;
		static void left();
		static void right();
		static void up();
		static void down();
		static void stop();
		static void stop2();
		static int getDirection();
		static int getMotion();
		static void shoot();
		static void computerShoot();
		static bool getShoot();
		static bool getComputerShoot();
		static void SetPlayer1(Player* player);
		static Player* GetPlayer1();
		static void SetPlayer2(Computer* player);
		static Computer* GetPlayer2();
		static void SetBall(Ball* ball);
		static Ball* GetBall();
		static void IncDiff();
		static int GetDiff();
		static void IncField();
		static int GetField();
		static void IncPlayerPoints();
		static void IncCompPoints();
		static int GetPlayerPoints();
		static int GetPlayerGames();
		static int GetCompPoints();
		static int GetCompGames();
		static void NewGame();
	};
}
