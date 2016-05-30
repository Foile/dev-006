#pragma once

#include <vector>
#include <string.h>
#include "Rental.h"

class Customer
{
private:
 char _name[80];
 std::vector<Rental*> _rentals;

public:
	Customer(char *name)
	{
		strcpy_s(_name,name);
	}
	~Customer(void)
	{
		_rentals.clear();
	}

	void addRental(Rental* rental)
	{
		_rentals.push_back(rental);
	}

	char* getName(void)
	{
		return _name;
	}
	char* statement(char* Buffer, int size);
};

