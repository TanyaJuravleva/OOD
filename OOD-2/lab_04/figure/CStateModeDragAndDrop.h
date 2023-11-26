#pragma once
#include "IStateBar.h"
#include "IBar.h"

class CStateModeDragAndDrop : public IStateBar
{
public:
	CStateModeDragAndDrop(IBar& barMode, IToolbar& toolbar)
		: m_barMode(barMode)
		, m_toolbar(toolbar)
	{
	}
	void ChangeDD() override
	{
		m_toolbar.
		m_barMode.SetModeDragAndDrop();
	}

	void ChangeF() override
	{
		m_barMode.SetModeFillColor();
	}
private:
	IBar& m_barMode;
	IToolbar& m_toolbar;
};