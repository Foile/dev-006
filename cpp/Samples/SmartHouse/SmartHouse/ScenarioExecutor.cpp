#include "ScenarioExecutor.h"
#include <wallaroo/registered.h>
#include "Controller.h"
#include <vector>

using namespace std;

using namespace wallaroo;

WALLAROO_REGISTER(ScenarioExecutor);


ScenarioExecutor::ScenarioExecutor(void):
	LightDevices("controllers",RegistrationToken())
{
}


ScenarioExecutor::~ScenarioExecutor(void)
{
}


void ScenarioExecutor::OffAll(void)
{
	for(Plug<Controller,collection>::iterator i = LightDevices.begin(); i != LightDevices.end(); i++)
	{
		cxx0x::shared_ptr<Controller> c = i->lock();
		c->Down();
	}
}
