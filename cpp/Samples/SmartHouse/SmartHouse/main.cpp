#include <iostream>
#include <wallaroo/catalog.h>
#include "ScenarioExecutor.h"

using namespace wallaroo;
using namespace ::std;

#define ZWAVE
int main()
{
	Catalog root;
#ifdef ZWAVE
	root.Create("ProtocolDriver","ZWaveProtocolImpl");
#else
	root.Create("ProtocolDriver","ZigBeeImpl");
#endif
	root.Create("GuestRoomLight","Dimmer",(const char*)"A1");
	root.Create("WCLight","SimpleSwitcher",(const char*)"A2");
	root.Create("BadroomLight","Dimmer",(const char*)"A3");
	root.Create("Executor","ScenarioExecutor");

	use(root["ProtocolDriver"]).as("lowleveldriver").of(root["GuestRoomLight"]);
	use(root["ProtocolDriver"]).as("lowleveldriver").of(root["WCLight"]);
	use(root["ProtocolDriver"]).as("lowleveldriver").of(root["BadroomLight"]);
	
	use(root["GuestRoomLight"]).as("controllers").of(root["Executor"]);
	use(root["WCLight"]).as("controllers").of(root["Executor"]);
	use(root["BadroomLight"]).as("controllers").of(root["Executor"]);

	if(!root.IsWiringOk())
	{
		cout << "Oops... Problem with initialization device" << endl;
		return 1;
	}
	shared_ptr<ScenarioExecutor> executor = root["Executor"];
	executor->OffAll();

	return 0;
}