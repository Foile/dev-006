#pragma once
#include "controller.h"
class Dimmer :
	public Controller
{
public:
	Dimmer(const char*);
	~Dimmer(void);
	
	void Up(void);
	void Down(void);
};

