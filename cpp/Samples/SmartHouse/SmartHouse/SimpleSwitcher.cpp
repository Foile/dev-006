#include "SimpleSwitcher.h"
#include <iostream>

using namespace std;

WALLAROO_REGISTER(SimpleSwitcher,const char*);


SimpleSwitcher::SimpleSwitcher(const char* Address) : Controller(Address)
{
}


SimpleSwitcher::~SimpleSwitcher(void)
{
}


void SimpleSwitcher::Up(void)
{
	cout << "SimpleSwitcher::" << "Power on"<< endl;
	WallDevice->SendCommand("+",Address);
}


void SimpleSwitcher::Down(void)
{
	cout << "SimpleSwitcher::" << "Power off" << endl;
	WallDevice->SendCommand("-",Address);
}
