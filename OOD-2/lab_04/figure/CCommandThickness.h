#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"
#include "IToolbar.h"
#include "CShapeOutlineThicknessVisitor.h"

class CCommandThickness : public ICommand
{
public:
	CCommandThickness(IToolbar& bar, int thick)
		: m_bar(bar)
		, m_thick(thick)
	{
	}
	void Execute() override
	{
		auto arrInd = m_bar.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			CShapeOutlineThicknessVisitor visitor(m_thick);
			m_bar.GetShapes()[arrInd[i]]->SetFillColor(visitor);
			//m_bar.GetShapes()[arrInd[i]]->SetOutlineThickness(m_thick);
		}
	}
private:
	IToolbar& m_bar;
	int m_thick;
};