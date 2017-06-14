// myOCR.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	Settings user(false,4,1,8,35,10,"01.bmp");
	Image img(user);
	Strainer S(img, user);
	S.display();
	system("pause");
    return 0;
}

