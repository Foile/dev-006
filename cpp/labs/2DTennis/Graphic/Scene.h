#pragma once
#include <vector>
#include "GraphicObject.h"

using namespace std;

namespace Graphics
{
	class Scene
	{
	private:
		vector<GraphicObject*> *T_objects;
	public:
		Scene(void);
		~Scene(void);
		vector<GraphicObject*>* GetAll();
		void AddObject(GraphicObject* object);
	};
}
