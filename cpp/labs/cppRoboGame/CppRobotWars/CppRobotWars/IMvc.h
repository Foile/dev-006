#pragma once

namespace RobotWar
{
	namespace MVC
	{	
/**
*	@brief Интерфейс наблюдателя событий
*/
		template <typename EARG>
		class IObserver
		{
		public:
		///Метод обработки события. Вызывается при рассылки события объектом класса EventDelegate
		 virtual void Update(EARG & Sender)=0;
		};
/**
*	@brief Интерфейс класса, предоставляющего многоадресную рассылку о событиях
*/
		template <typename EARG>
		class ISubject
		{
		public:
		///Регистрация наблюдателя события
		/// @param observer - адрес объекта наблюдателя, класс которого реализует шаблонный интерфейс IObserver
		 virtual void Attach(IObserver<EARG> *observer)=0;
		///отказ наблюдателя от получения события
		/// @param observer - адрес объекта наблюдателя
		 virtual void Detach(IObserver<EARG> *observer)=0;
		///Генерация события
		/// @param Sender - Параметры события
		 virtual void Notify(EARG & Sender)=0;
		};
		
	}
}
