#pragma once
#include <string.h>


class Movie
{
private:
	char _title[100];
	int _priceCode;

public:

   enum PriceCodeType
   {
	   CHILDREN,
	   REGULAR,
	   NEW_RELEASE
   };
	Movie(char *title,int priceCode)
	{
		strcpy_s(_title,title);
		_priceCode = priceCode;
	}
	
	int getPriceCode(void)
	{
		return _priceCode;
	}

	void setPriceCode(int priceCode)
	{
		_priceCode = priceCode;
	}
	char* getTitle()
	{
		return _title;
	}
};

