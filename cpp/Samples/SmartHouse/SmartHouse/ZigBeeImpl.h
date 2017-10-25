#pragma once
#include "ihal.h"
class ZigBeeImpl :
	public IHal
{
public:
	ZigBeeImpl(void);
	~ZigBeeImpl(void);
	void SendCommand(void* Command, const char* Address);
	void ReceiveCommand(void* Command, const char* Address);
	     
};

