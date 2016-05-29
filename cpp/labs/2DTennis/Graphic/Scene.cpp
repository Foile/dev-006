#include "Scene.h"

using namespace Graphics;

Scene::Scene(void)
{
	vector<GraphicObject*> *newVector =	new vector<GraphicObject*>();
	newVector->clear();
	T_objects = newVector;
}

Scene::~Scene(void)
{
}

vector<GraphicObject*>* Scene::GetAll()
{
	return T_objects;
}
void Scene::AddObject(GraphicObject* object)
{
	T_objects->push_back(object);
}
