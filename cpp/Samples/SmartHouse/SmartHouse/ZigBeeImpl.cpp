#include "ZigBeeImpl.h"
#include <iostream>
#include <wallaroo/registered.h>

using namespace std;
using namespace wallaroo;

WALLAROO_REGISTER(ZigBeeImpl);

ZigBeeImpl::ZigBeeImpl(void)
{
}


ZigBeeImpl::~ZigBeeImpl(void)
{
}


void ZigBeeImpl::SendCommand(void* Command, const char* Address)
{
	cout << "Send ZigBee command : " << (char*) Command << "to " << Address << endl;
}


void ZigBeeImpl::ReceiveCommand(void* Command, const char* Address)
{
	cout << "Receive ZigBee command : " << (char*) Command << "to " << Address << endl;
}
