#include <windows.h>
#include "Application.h"
#include "../Graphic/ObjectStorage.h"
#include "../Graphic/Scene.h"
#include "../Graphic/DirectXEngine.h"
#include "../Graphic/DirectXObject.h"
#include "../Graphic/PhysicEngine.h"
#include "../Graphic/Controller.h"
#include "../Graphic/Player.h"
#include "../Graphic/Computer.h"
#include "../Graphic/defines.h"
#include "../Graphic/Field.h"
#include "../Graphic/Ball.h"
#include "../Graphic/MainMenu.h"
#include "../Graphic/Settings.h"
#include "../Graphic/Statistic.h"

using namespace Graphics::MWindows;
using namespace Graphics;


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR cmd, int showCmd)
{
	
	Application::Init(hInst);
	Window* n1 = Application::Inst().CreateNewWindow("2D Tennis", 
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600);
	
	DirectXEngine* engine = new DirectXEngine(n1->GetHWND());
	engine->Init();
	Controller::SetGraphics(engine);
	Field* field = new Field(engine);
	Ball* ball = new Ball(engine, "ball.png");
	Player* player = new Player(engine, "pl1.png");
	Computer* computer = new Computer(engine, "comp1.png");
	MainMenu* mainMenu = new MainMenu(engine, "pl1.png");
	Settings* settings = new Settings(engine, "pl1.png");
	Statistic* stat = new Statistic(engine, "pl1.png");

	Controller::SetPlayer1(player);
	Controller::SetPlayer2(computer);
	Controller::SetBall(ball);

	Scene* menu = new Scene();
	Scene* sets = new Scene();
	Scene* game = new Scene();

	menu->AddObject(mainMenu);
	sets->AddObject(settings);

	game->AddObject(field);
	game->AddObject(ball);
	game->AddObject(computer);
	game->AddObject(player);
	game->AddObject(stat);

	ObjectStorage::Inst().SetScene(MAIN_MENU, menu);
	ObjectStorage::Inst().SetScene(SETTINGS, sets);
	ObjectStorage::Inst().SetScene(GAME, game);
	ObjectStorage::Inst().SetCurrentScene(MAIN_MENU);


	player->SetWidth(120);
	player->SetHeight(123);
	player->SetRotationPoint(0.5f, 1.0f,0.0f);
	player->SetX(0.5f);
	player->SetY(0.6f);

	computer->SetWidth(120);
	computer->SetHeight(123);
	computer->SetRotationPoint(0.5f, 1.0f,0.0f);
	computer->SetX(0.5f);
	computer->SetY(0.0f);

	ball->SetWidth(50);
	ball->SetHeight(55);
	ball->SetRotationPoint(0.5f, 1.0f,0.0f);
	ball->SetX(0.5f);
	ball->SetY(0.6f);

	PhysicEngine* physic = new PhysicEngine();
	DWORD current = GetTickCount();
	MSG msg;
	PeekMessage(&msg, 0,0,0,0);
	while(msg.message != WM_QUIT)
		{
			if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				DWORD s = GetTickCount();
				if ((s - current) >= 40)
				{
					current = s;
					physic->Update(40);
					engine->Redraw();
				}
			}
	}
	return msg.wParam;
}