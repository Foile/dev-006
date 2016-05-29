#include "MenuHelper.h"
#include <windows.h>
#include "Controller.h"

using namespace Graphics;

MenuHelper::MenuHelper(void)
{
}

MenuHelper::~MenuHelper(void)
{
}


void MenuHelper::ClickMenu(int lineNumber)
{
	switch (ObjectStorage::Inst().GetCurrentType())
	{
		case GameScene::MAIN_MENU:
		{
			switch (lineNumber)
			{
				case 1:
				{
					ObjectStorage::Inst().SetCurrentScene(GameScene::GAME);
					Controller::NewGame();
					break;
				}
				case 2:
				{
					ObjectStorage::Inst().SetCurrentScene(GameScene::SETTINGS);
					break;
				}
				case 3:
				{
					exit(0);
					break;
				}
			}
			break;
		}
		case GameScene::SETTINGS:
		{
			switch (lineNumber)
			{
				case 1:
				{
					Controller::IncDiff();
					break;
				}
				case 2:
				{
					Controller::IncField();
					break;
				}
				case 3:
				{
					ObjectStorage::Inst().SetCurrentScene(GameScene::MAIN_MENU);
					break;
				}
			}
			break;
		}
		case GameScene::GAME:
		{
			return;
		}
	}
}