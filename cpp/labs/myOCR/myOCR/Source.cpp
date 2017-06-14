#include "stdafx.h"

//	методы класса Pixel
void Pixel::get(const double& br)			// получить значение яркости
{
	brightness = static_cast<char>(br);
}
unsigned char& Pixel::put()					// передать значение яркости
{
	return brightness;
}
  
//	методы класса Image
unsigned int Image::putHeight()const
{
	return height;
}
unsigned int Image::putWidth()const
{
	return width;
}
float Image::valueF(unsigned int posX, const unsigned int& widthMask)
{
	float temp = 0.0;
	for (unsigned int i = 0; i < height; i++)
	{
		for (unsigned int j = 0; j < widthMask; j++, posX++)
		{
			if (j < (widthMask / 2)) temp -= pixel[posX].put();
			else temp += pixel[posX].put();
		}
		posX += width - widthMask;
	}
	return temp;
}
unsigned char& Image::operator[](const unsigned int& numberPix)const
{
	if (numberPix > height*width) exit(1);

	return pixel[numberPix].put();
}

//	методы класса Settings
void Settings::getMode()
{
	char ch;
	do{ 
		cout << "Выберете режим обучение(t) или обработка(p)";
		cin >> ch;
	} while (ch != 't' || ch != 'p' || ch != 'T' || ch != 'P' );
	(ch == 't' || ch == 'T') ? mode = true : mode = false;
}

//	методы класса Compliance
void Compliance::dispay()
{
	cout << endl << x0 << ' ' << xEnd << ' ' << nearestMatch << ' ' << CartesianDistance;
}

//	методы класса Sample
char Sample::returnMatch()
{
	return match;
}
void Sample::filtering(const Image& image, const unsigned int& x0, const unsigned int& xEnd)
{
	unsigned int numberPix = x0;				// начальная координата наложения фильтра
	unsigned int widthMask = (xEnd - x0) / 4;	// масштабируем фильтр по размеру отрезка
	widthMask *= 4;								
	unsigned int height = image.putHeight();	// высота изображения;
	unsigned int width = image.putWidth();		// ширина изображения;
	
	// Последовательно пропускаем пиксели через каждый фильтир 
	for (unsigned int i = 0; i < height; i++)	// внешний цикл наложения фильтров
	{
		for (unsigned int j = 0; j < widthMask; j++, numberPix++) // внутренний цикл наложения фильтров
		{
			// Накладываем фильтр 0
			{	
				Filtered[0] += image[numberPix]; 
			}
			// Накладываем фильтр 1										
			{
				if (j < (width / 2)) Filtered[1] -= image[numberPix];
				else Filtered[1] += image[numberPix];
			}	
		    // Накладываем фильтр 2
			{
				if (i < (height / 2)) Filtered[2] -= image[numberPix];
				else Filtered[2] += image[numberPix];
			}
			// Накладываем фильтр 3
			{
				if ((2 * i / height + 2 * j / widthMask) % 2) Filtered[3] += image[numberPix];
				else Filtered[3] -= image[numberPix];
			}
			// Накладываем фильтр 4
			{
				if (j <= (widthMask / 4) || j > (widthMask * 3 / 4)) Filtered[4] -= image[numberPix];
				else Filtered[4] += image[numberPix];
			}
			// Накладываем фильтр 5
			{
				if (j <= (height / 4) || j > (height * 3 / 4)) Filtered[5] -= image[numberPix];
				else Filtered[5] += image[numberPix];
			}
			// Накладываем фильтр 6
			{
				if (i <= (height / 2) && j <= (widthMask / 4) || i <= (height / 2) && j > (widthMask * 3 / 4) || i > (height / 2) && j > (widthMask / 4) && j <= (widthMask * 3 / 4))
					Filtered[6] -= image[numberPix];
				else Filtered[6] += image[numberPix];
			}
			// Накладываем фильтр 7
			{
				if (j <= (widthMask / 2) && i > (height / 4) && i <= (height * 3 / 4) || j > (widthMask / 2) && i <= (height / 4) || i > (height * 3 / 4) && j > (widthMask / 2))
					Filtered[7] -= image[numberPix];
				else Filtered[7] += image[numberPix];
			}
			// Накладываем фильтр 8
			{
				if (i > (height / 2) && j < (widthMask / 2) || i<(height / 2) && j>(widthMask / 2))
					if ((i / (height / 4) + j / (widthMask / 4)) % 2) Filtered[8] += image[numberPix];
					else Filtered[8] -= image[numberPix];
				else if ((i / (height / 4) + j / (widthMask / 4)) % 2) Filtered[8] -= image[numberPix];
				else Filtered[8] += image[numberPix];
			}
			// Накладываем фильтр 9
			{
				if ((j > (widthMask / 4) && j <= (widthMask / 2)) || j >= (widthMask * 3 / 4))
					Filtered[9] -= image[numberPix];
				else Filtered[9] += image[numberPix];
			}
			// Накладываем фильтр 10
			{
				if (i <= (height / 4) || (i > (height / 2) && i < (height * 3 / 4)))
					Filtered[10] -= image[numberPix];
				else Filtered[10] += image[numberPix];
			}
			// Накладываем фильтр 11
			{
				if (i <= (height / 2))
					if (j>(widthMask / 4) && j <= (widthMask / 2) || j >= (widthMask * 3 / 4))Filtered[11] -= image[numberPix];
					else Filtered[11] += image[numberPix];
				else if (j <= (widthMask / 4) || j>(widthMask / 2) && j<(widthMask * 3 / 4))Filtered[11] -= image[numberPix];
				else Filtered[11] += image[numberPix];
			}
			// Накладываем фильтр 12
			{
				if (j<(widthMask / 2))
					if ((i>(height / 4) && i <= (height / 2)) || i>(height * 3 / 4))Filtered[12] -= image[numberPix];
					else Filtered[12] += image[numberPix];
				else if (i <= (height / 4) || (i >= (height / 2) && i<(height * 3 / 4)))Filtered[12] -= image[numberPix];
				else Filtered[12] += image[numberPix];
			}
			// Накладываем фильтр 13
			{
				if (i<(height / 2))
					if ((i / (height / 4) + j / (widthMask / 4)) % 2)Filtered[13] += image[numberPix];
					else Filtered[13] -= image[numberPix];
				else if ((i / (height / 4) + j / (widthMask / 4)) % 2)Filtered[13] -= image[numberPix];
				else Filtered[13] += image[numberPix];
			}
			// Накладываем фильтр 14
			{
				if (j<(widthMask / 2))
					if ((i / (height / 4) + j / (widthMask / 4)) % 2)Filtered[14] -= image[numberPix];
					else Filtered[14] += image[numberPix];
				else if ((i / (height / 4) + j / (widthMask / 4)) % 2)Filtered[14] += image[numberPix];
				else Filtered[14] -= image[numberPix];
			}
			// Накладываем фильтр 15
			{
				if ((i / (height / 4) + j / (widthMask / 4)) % 2)Filtered[15] += image[numberPix];
				else Filtered[15] -= image[numberPix];
			}
		}
		numberPix += width - widthMask;
	}
}
void Sample::display()
{
	cout << endl << match << '|';
	for (int i = 0; i < QF; i++)
		cout << setw(7) << Filtered[i];
}
void Sample::diskOut()						// Запись в конец файла.
{
		cout << " Запись эталона в базу";
	cout << " Введите символ... ";  cin >> match;

	ofstream outfile;						// созадан поток вывода
	outfile.open("MatchBase.dat", ios::app | ios::out | ios::binary); // открыть для записи
	outfile.write((char*)this, sizeof(*this));	// Объект записан;
	outfile.close();	
}
float Sample::operator - (const Sample& match)
{
	long double tempDC = 0.0;
	for (int i = 0; i < QF; i++)
	{
		double minus = Filtered[i] - match.Filtered[i];
		tempDC += minus*minus;
	}
	return (float)(sqrt(tempDC));
}

//	методы класса Strainer
char Strainer::compareWithBase(float& MinCD) //сравнивает с эталонами, возвращает ближайший
{											 // и расстояние до него(&MinCD);
	char  nearestMatch = 0;
	float tempCD;				// текущее значение декартовова расстояния
	Sample tempSample;			// буфер для временного хранения эталонов
	fstream infile;				// открыть поток ввода из файла;
	infile.open("MatchBase.dat", ios::in | ios::binary);
	if (!infile) exit(3);
								// считываем значения эталонв из обучающей выборки:
	infile.read(reinterpret_cast<char*>(&tempSample), sizeof(tempSample));
	while (!infile.eof()) 
	{
		tempCD = *this - tempSample;	// находим декартово расстояние
		
		if (!nearestMatch || MinCD > tempCD)// если это первое сравнение или  
		{									// предыдущее декартово рсстояние больше
			MinCD = tempCD;					// сохраняем это как минимальное 
											// запоминаем эталон как наиболее близкий
			nearestMatch = tempSample.returnMatch();
		}						// считываем значения эталонв из обучающей выборки:
		infile.read(reinterpret_cast<char*>(&tempSample), sizeof(tempSample));
	}
	infile.close();
	return nearestMatch;		// вернём ближайший эталон
}
void Strainer::selection(Image& image, Settings& user)
{
	char way=0;					// направление обхода алгоритма обработки;
	list<Compliance>::iterator index = compliance.begin();
								// количество шагов
	unsigned int width = image.putWidth();
	unsigned int widthMask = user.widthMask;
	unsigned int stepOffset = user.stepOffset;
	unsigned int minInterval = user.minInterval;
	unsigned int maxInterval = user.maxInterval;
	int numberOfSteps = ((width - widthMask) / stepOffset);
	unsigned int j = 0;			// индекс циклов обработки
	unsigned int posX = 0;		// текущая позиция по X
	float MinCD;				// минимальное декартово расстояние
	char  nearestMatch = 0;		// ближайший эталон
	cout << "selection..." << endl;
						// внешний цикл обработки. обход по ширине изображения с заданным шагом 
	for (int i = 0; i <= numberOfSteps; i++)
	{
		posX += stepOffset;	// ищем левую границу искомого объекта(через экстремуму)
		if (((image.valueF(posX - stepOffset, widthMask) < image.valueF(posX, widthMask))
			&& (image.valueF(posX, widthMask) > image.valueF(posX + stepOffset, widthMask)))
			|| ((image.valueF(posX - stepOffset, widthMask) > image.valueF(posX, widthMask))
				&& (image.valueF(posX, widthMask) < image.valueF(posX + stepOffset, widthMask))))
		{
			j = posX + minInterval;	// ищем правую границу искомого объекта(через экстремуму);
			while ((j+1-posX<maxInterval)&&(j+1<width))
			{
				if (((image.valueF(j - 1, widthMask) < image.valueF(j, widthMask))
					&& (image.valueF(j, widthMask) > image.valueF(j + 1, widthMask)))
					|| ((image.valueF(j - 1, widthMask) > image.valueF(j, widthMask))
					&& (image.valueF(j, widthMask) < image.valueF(j + 1, widthMask))))
				{
					for (int i = 0; i < QF; i++)Filtered[i] = 0.0;
					filtering(image, posX, j);
					if (user.mode)
					{
						cout << " x0 = " << posX << " xEnd = " << j << " записать в файл(y/n)?.. ";
						char ch;
						cin >> ch;
						if (ch == 'y')
							diskOut();
						cout << " сместится вправо по X0(если нет - 0): ";
						int offset = 0;
						cin >> offset;
						if (offset)
						{
							posX = offset;
							break;
						}
					}
					else {
						nearestMatch = compareWithBase(MinCD);

						way = 0;
						do {
							switch (way) {
							case 0: if (index != compliance.begin()) way = 1;
									else way = 3;								continue;
							case 1: if ((float((--index)->xEnd - posX) / float(j - posX)) > (user.percentOverlay / 100)) way = 2;
									else way = 3;								continue;
							case 2: if (index->CartesianDistance > MinCD) { compliance.pop_back(); way = 3; }
									else { way = 4;	index = compliance.end(); }	continue;
							case 3: compliance.push_back(Compliance(posX, j, nearestMatch, MinCD));
								index = compliance.end(); way = 4;
							}
						} while (way != 4);
					}
				}
				j++;
			}
		}
	}
}
void Strainer::display()
{
	list<Compliance>::iterator iter;
	for (iter = compliance.begin(); iter != compliance.end(); ++iter)
		iter->dispay();
}