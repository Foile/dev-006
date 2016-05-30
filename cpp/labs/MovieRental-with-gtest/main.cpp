#include <locale.h>
#include "Movie.h"
#include "Customer.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Movie movie1("Рио2",Movie::CHILDREN);
	Movie movie2("Елки 2",Movie::REGULAR);
	Movie movie3("Отель Гранд Будапешт", Movie::NEW_RELEASE);

	Rental rio2(&movie1,3);
	Rental elki2(&movie2,4);
	Rental grandHotel(&movie3,10);

	Customer customer("Videoman");
	customer.addRental(&rio2);
	customer.addRental(&elki2);
	customer.addRental(&grandHotel);

	char Buffer[300];
	customer.statement(Buffer,300);
	printf_s(Buffer);

	return 0;
}