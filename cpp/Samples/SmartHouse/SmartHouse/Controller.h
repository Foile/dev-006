#pragma once

#include <wallaroo/registered.h>
#include "IHal.h"

using namespace wallaroo;

class Controller :
	public Device
{
public:
	Controller(const char* Address);
	~Controller(void);
protected:
	Plug<IHal> WallDevice;
	const char* Address;
public:
	void virtual Up()=0;
	void virtual Down()=0;
};

