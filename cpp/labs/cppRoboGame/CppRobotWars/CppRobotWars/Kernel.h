#pragma once
#include "irobotoperation.h"
#include "RobotInternal.h"
#include "thread.h"
#include "MyException.h"
#include "TalkThread.h"
#include "EventDelegate.h"
#include <map>
#include <vector>

using namespace std;
using namespace RobotWar::MVC;

namespace RobotWar
{
	namespace Kernel
	{
/**
*	@brief Исключение, которое выбрасывается при некорректных параметрах, переданных 
*	при вызове методов интерфейса IRobotOperation
*/
	class ParametersContractError : public RobotWarException 
	{
	};
/**
*	@brief Исключение, которое выбрасывается при невозможности переместить робота
    в указанные координаты, так как в этих координатах находится какой-то объект
*/
	class NoValidMove : public RobotWarException
	{
	};
/**
	@brief Класс, реализующий ядро игровой программы, работающей в отдельном потоке
*/
	class Kernel :
		public IRobotOperation, 
		public RobotWar::Infrastructure::Thread
	{
	private:
		///Роботы, которые учавствуют в игре
		map<IRobot*,RobotInternal*> m_GameMembersStorage;
		Kernel(void);
		///указатель на ядро. Используется в паттерне Singleton
		static Kernel *m_Kernel;
	public:	
		///многоадресный указатель-делегат на событие OnMove. Данное событие вызывается при 
		///перемещении любого робота
		EventDelegate<MoveEvent> OnMove;
		///многоадресный указатель-делегат на событие OnMove. Данное событие вызывается при 
		///при выстреле любого робота
		EventDelegate<FireEvent> OnFire;
		///многоадресный указатель-делегат на событие OnFire. Данное событие вызывается при 
		///передаче между роботами сообщения
		EventDelegate<TalkEvent> OnTalk;
		///многоадресный указатель-делегат на событие OnTalk. Данное событие вызывается при 
		///добавлении нового робота в игру
		EventDelegate<NewRobotEvent> OnNewRobot;

		virtual ~Kernel(void);
		/// Перемещает робота на указанное количество координат (не более 3)
		/// @param Sender - робот, который обращается к ядру
		/// @param x - координата по x (0<=x<3)
		/// @param y - координата по y (0<=y<3)
		void Move(IRobot *Sender,int x, int y);
		/// Позволяет роботу произвести выстрел на указанное расстояние (не более 3)
		/// @param Sender - робот, который обращается к ядру
		/// @param x - координата по x (0<=x<3)
		/// @param y - координата по y (0<=y<3)
		void Fire(IRobot *Sender,int x, int y);
		///позволяет роботу получить информацию о существование других роботов в радиусе depth
		/// @param Sender - робот, который обращается к ядру. Следует указывать this
		/// @param depth - глубина просмотра (0<=depth<3)
		/// @param CountPoints - количество элементов в буфере для заполнения массива координат
		/// @param pPoints - массив структур PT для заполнения координат, в которых есть объекты
		void LookAround(IRobot *Sender,int depth, int CountPoints, RobotWar::PT* pPoints);
		///позволяет роботу отправить сообщение другому роботу
		/// @param Sender - робот, который обращается к ядру
		/// @param RobotName - строка, содержащая имя робота, которому пересылается сообщение
		/// @param TalkData - буфер, содержащий передаваемые другому роботу данные
		void SendMsg(IRobot *Sender,char *RobotName, void *TalkData);
		/// Метод выполнения потока ядраа
		void Execute(void);
		///Запуск потока ядра (Запуск игры)
		void Start(void);
		///Останов потока ядра (Останов игры)
		void Stop(void);
		///Приостановка потока
		void Suspend(void);
		///Возобновление потока
		void Resume(void);

		///добавляет робота как участника игры
		/// @param Robot - Указатель на добавляемого робота
		void AddRobot(RobotInternal* Robot);
	    

		static Kernel* CreateKernel(void);
	private:
		///список асинхронных сообщений, передаваемых между роботами
		vector<TalkThread*> m_TalkThreadStorage;
	};
	}	
}