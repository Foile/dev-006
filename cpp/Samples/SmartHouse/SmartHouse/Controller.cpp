#include "Controller.h"

using namespace wallaroo;


Controller::Controller(const char* Address) : 
	
	WallDevice("lowleveldriver",RegistrationToken()),Address(Address)
{
}


Controller::~Controller(void)
{
}
