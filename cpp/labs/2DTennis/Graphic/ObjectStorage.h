#pragma once
#include <map>
#include "GraphicObject.h"
#include "Scene.h"
using namespace std;

namespace Graphics
{
	enum GameScene
	{
		MAIN_MENU,SETTINGS, GAME
	};
	class ObjectStorage
	{
	private:
		static ObjectStorage *T_pointer;
		ObjectStorage();
		ObjectStorage(ObjectStorage& source);
		map<GameScene, Scene*> *T_scenes;
		Scene* T_currentScene;
		GameScene T_type;
	public:
		static ObjectStorage& Inst();
		~ObjectStorage(void);
		void Clear();
		void SetScene(GameScene sceneType, Scene* scene);
		void SetCurrentScene(GameScene type);
		Scene* GetCurrentScene();
		GameScene GetCurrentType();
		Scene* GetScene(GameScene gameScene);
		vector<GraphicObject*>* GetObjects();
	};
}