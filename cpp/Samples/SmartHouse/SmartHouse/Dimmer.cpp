#include "Dimmer.h"
#include <iostream>

using namespace ::std;

WALLAROO_REGISTER(Dimmer,const char*)


	Dimmer::Dimmer(const char* Address) : Controller(Address)
{
}


Dimmer::~Dimmer(void)
{
}


void Dimmer::Up(void)
{
	cout <<"Dimmer::" << "increase power" << endl;
	WallDevice->SendCommand("+++",Address);
}


void Dimmer::Down(void)
{
	cout << "Dimmer::" << "decrease power" << endl;
	WallDevice->SendCommand("---",Address);
}
