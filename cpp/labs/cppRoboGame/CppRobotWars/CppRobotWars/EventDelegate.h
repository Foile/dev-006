#pragma once
#include "imvc.h"
#include "robotinternal.h"
#include <list>

using namespace std;


namespace RobotWar
{
 	namespace MVC
	{
/**
*	@brief Общий класс для параметров событий. Используйте этот класс для 
*   создания своих классов параметров событий ядра программы
*/
		class Event
		{
		private:
			///Указатель на робота, который является источником событий
			RobotWar::RobotInternal  *  m_SenderRobot;
		public:
			///Получение указателя на объект робота для последующих получений
			///дополнительных данных о состоянии и координатах робота
			RobotWar::RobotInternal*  GetSender() const { return m_SenderRobot;}
			///конструктор по умолчанию
			Event() : m_SenderRobot(NULL) {}
			///конструктор класса.
			///@param Sender - указатель на робота, который является причиной события
			Event(RobotInternal *Sender) : m_SenderRobot(Sender) {}
		};
/**
*	@brief Параметры события OnMove ядра битвы роботов
*/
		class MoveEvent : public Event 
		{
		private:
			///старая координата x (до перемещения робота)
			int m_OldX;
			///старая координата y (до перемешения робота)
			int m_OldY;
		public:
			///получение старой координаты x
			int GetOldX() { return m_OldX; }
			///получение старой координты y
			int GetOldY() { return m_OldY; }
			///Конструктор класса
			/// @param Sender - Указатель на робота, который является источником события
			/// @param OldX - старая x координата
			/// @param OldY - старая y координата
			MoveEvent(RobotInternal *Sender,int OldX,int OldY) : Event(Sender),m_OldX(OldX),
			m_OldY(OldY) {}
		};

/**
*	@brief Параметры события OnTalk ядра битвы роботов
*/
		class TalkEvent : public Event
		{
		public:
			TalkEvent(RobotInternal *Sender) : Event(Sender) {}
		};
/**
*	@brief Параметры события OnFire ядра битвы роботов
*/
		class FireEvent : public Event
		{
		private:
			///Указатель на уничтоженного робота
			RobotInternal *m_KilledRobot;
		public:
			///Получить сведения об успешном выстреле. Возвращает true, если 
			///в результате выстрела был уничтожен робот
			bool GetSuccess() { return m_KilledRobot!=NULL;}
			///Конструктор класса
			///@param Sender - робот, который произвел выстрел
			///@param KilledRobot - подбитый робот, если не равен NULL, в противном случае, выстрел цели не достиг
			FireEvent(RobotInternal *Sender,RobotInternal *KilledRobot=NULL) 
				: Event(Sender),m_KilledRobot(KilledRobot) {}
		};

/**
*	@brief Параметры события OnNewRobotEvent ядра битвы роботов
*/
		class NewRobotEvent: public Event
		{
		public:
			///Конструктор класса
			/// @param Sender - добавленный пользователь робот в игру
			NewRobotEvent(RobotInternal *Sender) : Event(Sender) {}
		};

/**
*	@brief Класс многоадресной рассылки событий в паттерне "Модель-вид-контроллер"
*/
		template <typename EARG>
		class EventDelegate :
			public RobotWar::MVC::ISubject<EARG>
		{
		public:
			
			~EventDelegate(void){m_ObserversStorage.clear();}
			///Регистрация наблюдателя события
			/// @param observer - адрес объекта наблюдателя, класс которого реализует шаблонный интерфейс IObserver
			void Attach(IObserver<EARG> *observer) {m_ObserversStorage.push_back(observer);}
			///отказ наблюдателя от получения события
			/// @param observer - адрес объекта наблюдателя
			void Detach(IObserver<EARG> *observer) {m_ObserversStorage.remove(observer);}
			///Генерация события
			/// @param Sender - Параметры события
			void Notify(EARG &Sender)
			{
				for(list<IObserver<EARG>*>::iterator i = m_ObserversStorage.begin();
					i != m_ObserversStorage.end();
					i++)
					(*i)->Update(Sender);
					;
			}

		private:
			///Список наблюдателей, получающих рассылку события
			list<IObserver<EARG>*> m_ObserversStorage;
		};
	}
}
