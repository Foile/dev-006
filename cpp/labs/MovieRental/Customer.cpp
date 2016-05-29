#include "Customer.h"






char* Customer::statement(char* Buffer, int size)
{
	double totalAmount = 0;
	int curPos = 0;
	int frequentRenterPoints = 0;
	std::vector<Rental*>::iterator rentals = _rentals.begin();

	curPos = sprintf_s(Buffer,size,"%s %s\n","���� ������ ���",getName());

	while(rentals != _rentals.end())
	{
		double thisAmount = 0;
		Rental* each = *rentals;
		//���������� ����� ��� ������ ������
		switch(each->getMovie()->getPriceCode())
		{
		case Movie::REGULAR:
			thisAmount+=2;
			if(each->getDaysRented() > 2)
				thisAmount+=(each->getDaysRented()- 2) * 15;
			break;
		case Movie::NEW_RELEASE:
			thisAmount += each->getDaysRented() * 3;
		    break;
		case Movie::CHILDREN:
			thisAmount+=15;
			if(each->getDaysRented() > 3)
				thisAmount += (each->getDaysRented() -3)*15;
			break;
		}
		//�������� ���� ��� ��������� ����������
		frequentRenterPoints++;
		//����� �� ������ ������� �� ��� ���
		if(each->getMovie()->getPriceCode() == Movie::NEW_RELEASE && each->getDaysRented() > 1)
			frequentRenterPoints++;
		//�������� ���������� ������
		curPos += sprintf_s(Buffer+curPos,size-curPos,"\t%s\t%lf\n",each->getMovie()->getTitle(),thisAmount);
		totalAmount+=thisAmount;
		rentals++;
	}

	//�������� ������ ����������
	curPos+=sprintf_s(Buffer+curPos,size-curPos,"����� ������������� ���������� %lf\n�� ���������� %d ����� �� ����������",totalAmount,
		frequentRenterPoints);
	return Buffer;
}
