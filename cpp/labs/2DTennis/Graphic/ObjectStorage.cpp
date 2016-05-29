#include "ObjectStorage.h"
using namespace Graphics;
using namespace std;

ObjectStorage* ObjectStorage::T_pointer = 0;

ObjectStorage::ObjectStorage(void)
{
	static map<GameScene, Scene*> newMap;
	newMap.clear();
	T_scenes = &newMap;
}

ObjectStorage::~ObjectStorage(void)
{

}

ObjectStorage::ObjectStorage(ObjectStorage& source)
{
}

ObjectStorage& ObjectStorage::Inst()
{
	if (!T_pointer)
		T_pointer = new ObjectStorage();
	return *T_pointer;
}


void ObjectStorage::Clear()
{
	
}

void ObjectStorage::SetScene(GameScene sceneType, Scene* scene)
{
	(*T_scenes)[sceneType] = scene;
}

void ObjectStorage::SetCurrentScene(GameScene type)
{
	T_type = type;
	T_currentScene = (*T_scenes)[type];
}

Scene* ObjectStorage::GetCurrentScene()
{
	return T_currentScene;
}
Scene* ObjectStorage::GetScene(GameScene gameScene)
{
	return (*T_scenes)[gameScene];
}

vector<GraphicObject*>* ObjectStorage::GetObjects()
{
	if (T_currentScene)
		return T_currentScene->GetAll();
	else
		return 0;
}

GameScene ObjectStorage::GetCurrentType()
{
	return T_type;
}