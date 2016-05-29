#pragma once
#include "imvc.h"
#include "EventDelegate.h"
#include <windows.h>

using namespace RobotWar::MVC;
/**
*	@brief Пример вида для битвы роботов
*	
* Данный класс реализует обработку событий от модели (класс Kernel)
* Для получения возможности обработки события от ядра необходимо реализовать
* шаблонный интерфейс IObserver<T>, где T класс унаследованный от класса Event 
* и содержащий параметры, связанные с событием
*/
class SampleView :
	public IObserver<MoveEvent>,
	public IObserver<TalkEvent>,
	public IObserver<NewRobotEvent>
{
private:
	///Контекст окна
	HDC m_HDC;
	///Дескриптор окна
	HWND m_hWnd;
public:
	/**
	 Конструктор
	 @param hWnd - дескриптор окна, соответствующего виду в паттерне МОДЕЛЬ-ВИД-КОНТРОЛЛЕР
	*/
	SampleView(HWND hWnd);
	///деструктор
	~SampleView(void);
	/**
	Обработчик события  OnMove от ядра игры
	@param e - Параметр события OnMove
	*/
	void Update(MoveEvent &e);
	/**
	Обработчик события  OnTalk от ядра игры
	@param e - Параметр события OnTalk
	*/
	void Update(TalkEvent &e);
	/**
	Обработчик события  OnNewRobot от ядра игры
	@param e - Параметр события TalkEvent
	*/
	void Update(NewRobotEvent &e);
};
