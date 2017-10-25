#include "ZWaveProtocolImpl.h"
#include <iostream>
#include <wallaroo/registered.h>

using namespace wallaroo;
using namespace std;

WALLAROO_REGISTER(ZWaveProtocolImpl);

ZWaveProtocolImpl::ZWaveProtocolImpl(void)
{
}


ZWaveProtocolImpl::~ZWaveProtocolImpl(void)
{
}


void ZWaveProtocolImpl::SendCommand(void* Command,const char *Address)
{
	cout << "Send ZWave command : " << (char*) Command << "to " << Address << endl;
}


void ZWaveProtocolImpl::ReceiveCommand(void* Command, const char* Address)
{
	cout << "Receive ZWave command : " << (char*) Command << "to " << Address << endl;
}
