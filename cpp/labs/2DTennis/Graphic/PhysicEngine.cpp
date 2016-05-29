#include "PhysicEngine.h"
#include "GraphicObject.h"
#include "ObjectStorage.h"
#include "Controller.h"
#include <vector>

using namespace std;
using namespace Graphics;

PhysicEngine::PhysicEngine(void)
{
	
}

PhysicEngine::~PhysicEngine(void)
{
}


void PhysicEngine::Update(unsigned int dt)
{
	vector<GraphicObject*>* objects = ObjectStorage::Inst().GetCurrentScene()->GetAll();
	for (unsigned int i = 0; i < objects->size(); i++)
	{
		GraphicObject* obj = (*objects)[i];
		obj->Update(dt);
	}
	if (Controller::getShoot())
		Controller::shoot();
}