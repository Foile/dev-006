#pragma once
#ifndef MAINHEAD
#define MAINHEAD
#define QF 16						// Количество филььров
class Settings						// параметры вводимые пользователем
{
private:
	bool mode;
	unsigned int widthMask;			// ширина накладываемой маски при поиске экстреммум f1
	unsigned int stepOffset;		// шаг смещения при поиске экстреммум f1
	unsigned int minInterval;		// минимальная ширина символа в пикселях
	unsigned int maxInterval;		// максимальная ширина символа в пикселях
	float percentOverlay;			// процент наложения
	char fileName[40];				// имя файла изображением
public:
	Settings(bool m, int wM, int sO, int minIn, int maxIn, float pO, char* fname)
	{

		mode = m;
		widthMask = wM;			// ширина накладываемой маски при поиске экстреммум f1
		stepOffset = sO;		// шаг смещения при поиске экстреммум f1
		minInterval = minIn;	// минимальная ширина символа в пикселях
		maxInterval = maxIn;	// максимальная ширина символа в пикселях
		percentOverlay = pO;
		strcpy_s(fileName,fname);
	}
	void getMode();
	friend class Image;
	friend class Sample;
	friend class Strainer;
};
class Pixel						// хранит яркость пикселя
{
private:
	unsigned char brightness;			
public:
	Pixel() : brightness(0)
	{}
	void get(const double& br);			// получить значение яркости
	unsigned char& put();					// передать значение яркости
};
class Image						// хранит изображение в виде массива Pixel;
{
private:
	Image(const Image&)	{}					// Конструктор копирования;
protected:
	Pixel* pixel;								// указатель на массив;
	unsigned int height;						// высота изображение;
	unsigned int width;							// ширина изображения;
public:
	Image(Settings& user); // >> >> >> download.cpp						// конструктор
	~Image()
	{
		delete[]pixel;
	}
	unsigned int putHeight()const;
	unsigned int putWidth()const;
	unsigned char& operator [](const unsigned int& numberPix)const;
	float valueF(unsigned int posX, const unsigned int& widthMask);
};
class Sample								// находит хранит, и записывает эталоны;
{
protected:
	char match;								// номер эталона
	float Filtered[QF];						// результатналожения фильтров;
public:
	Sample()
	{
		for (int i = 0; i < QF; i++)Filtered[i] = 0.0;
	}
	Sample(float M[QF])
	{
		for (int i = 0; i < QF; i++)Filtered[i] = M[i];
	}
	char returnMatch();
	void filtering(const Image& image, const unsigned int& x0, const unsigned int& xEnd);
	void display();
	void diskOut();
	float operator - (const Sample& matchFiltred);
};
class Compliance
{
protected:
	int x0;							// Начаольная координата искомого объекта;
	int xEnd;						// конечная координата искомого объекта;
	char nearestMatch;				// номер эталона ближайшего по значению признаков;
	float CartesianDistance;		// декартово расстояние до ближайшего эталона;
public:
	Compliance() : x0(0), xEnd(0), nearestMatch(0), CartesianDistance(0.0)
	{ }
	Compliance(int X0, int End, int nM, float CD) :
		x0(X0), xEnd(End), nearestMatch(nM), CartesianDistance(CD)
	{ }
	void dispay();
	friend class Strainer;
};
class Strainer : public Sample		// выборка совпадений
{
protected:
	list<Compliance> compliance;
public:
	Strainer(Image& image, Settings& user)
	{
		selection(image, user);
	}
	char compareWithBase(float& MinCD);
	void selection(Image& image, Settings& user);
	void display();
};
#endif // !MAINHEAD
