#pragma once
#include "IStateBar.h"
#include "IBar.h"

class CStateModeFillColor : public IStateBar
{
public:
	CStateModeFillColor(IBar& barMode)
		: m_barMode(barMode)
	{
	}
	void ChangeDD() override
	{
		
		m_barMode.SetModeDragAndDrop();
	}

	void ChangeF() override
	{
		m_barMode.SetModeFillColor();
	}
private:
	IBar& m_barMode;
};