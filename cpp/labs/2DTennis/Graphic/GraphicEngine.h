#pragma once
#include <windows.h>
#include "GraphicObject.h"
#include <vector>
using namespace std;

namespace Graphics
{
	class GraphicEngine
	{
	private:

	protected:
		HWND T_window;
	public:
		GraphicEngine(HWND);
		virtual ~GraphicEngine(void);
		virtual void Init() = 0;
		virtual void Redraw() = 0;
	};

}