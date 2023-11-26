#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"
#include "IToolbar.h"

class CCommandNewPosition : public ICommand
{
public:
	CCommandNewPosition(IToolbar& bar, int x, int y)
		: m_bar(bar)
		, m_x(x)
		, m_y(y)
	{
	}
	void Execute() override
	{
		auto arrInd = m_bar.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			m_bar.GetShapes()[arrInd[i]]->SetPosition(m_x, m_y);
		}
	}
private:
	IToolbar& m_bar;
	int m_x;
	int m_y;
};