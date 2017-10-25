#pragma once
#include "controller.h"
class SimpleSwitcher :
	public Controller
{
public:
	SimpleSwitcher(const char*);
	~SimpleSwitcher(void);
	void Up(void);
	void Down(void);
};

