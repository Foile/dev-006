#pragma once
#include "ihal.h"
class ZWaveProtocolImpl :
	public IHal
{
public:
	ZWaveProtocolImpl(void);
	virtual ~ZWaveProtocolImpl(void);
	void SendCommand(void* Command,const char* Address);
	void ReceiveCommand(void* Command, const char* Address);
};

