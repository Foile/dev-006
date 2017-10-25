#pragma once
#include <wallaroo/device.h>
#include "Controller.h"

using namespace wallaroo;

class ScenarioExecutor :
	public Device
{
private:
	Plug<Controller,collection> LightDevices; 
public:
	ScenarioExecutor(void);
	~ScenarioExecutor(void);
	void OffAll(void);
};

