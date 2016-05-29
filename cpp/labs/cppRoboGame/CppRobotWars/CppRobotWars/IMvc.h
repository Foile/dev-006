#pragma once

namespace RobotWar
{
	namespace MVC
	{	
/**
*	@brief ��������� ����������� �������
*/
		template <typename EARG>
		class IObserver
		{
		public:
		///����� ��������� �������. ���������� ��� �������� ������� �������� ������ EventDelegate
		 virtual void Update(EARG & Sender)=0;
		};
/**
*	@brief ��������� ������, ���������������� ������������� �������� � ��������
*/
		template <typename EARG>
		class ISubject
		{
		public:
		///����������� ����������� �������
		/// @param observer - ����� ������� �����������, ����� �������� ��������� ��������� ��������� IObserver
		 virtual void Attach(IObserver<EARG> *observer)=0;
		///����� ����������� �� ��������� �������
		/// @param observer - ����� ������� �����������
		 virtual void Detach(IObserver<EARG> *observer)=0;
		///��������� �������
		/// @param Sender - ��������� �������
		 virtual void Notify(EARG & Sender)=0;
		};
		
	}
}
