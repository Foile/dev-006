#pragma once

#include <wallaroo/device.h>

using namespace wallaroo;

class IHal : public Device
{
public:

//	IHal(void)
//	{
//	}

	~IHal(void)
	{
	}
	virtual void SendCommand(void* Command,const char* Address) = 0;
	virtual void ReceiveCommand(void* Command,const char* Address) = 0;
};

