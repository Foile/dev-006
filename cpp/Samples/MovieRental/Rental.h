#pragma once

#include "Movie.h"


class Rental
{
private:
	Movie *_movie;
	int _daysRented;
public:
	Rental(Movie* movie, int daysRented);
	~Rental(void);

	int getDaysRented(void)
	{
		return _daysRented;
	}
	Movie* getMovie(void)
	{
		return _movie;
	}
};

