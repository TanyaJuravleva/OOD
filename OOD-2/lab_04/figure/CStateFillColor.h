#pragma once
//#include "IStateShapes.h"
#include "IToolbar.h"
//#include "IShapeDecorator.h"
#include "CCommandFillColor.h"
#include "CComandOutlineColor.h"
#include "CCommandThickness.h"
#include "CCommandAddFigure.h"
#include "CCommandNewPosition.h"
#include "CCommandGroupFigures.h"
#include "CCommandUngoupFigures.h"

class CStateFillColor : public IStateShapes
{
public:
	CStateFillColor(IToolbar& bar)
		: m_bar(bar)
	{
		for (int i = 0; i < m_bar.GetShapes().size(); i++)
		{
			IShapeDecorator* m = m_bar.GetShapes()[i]->Clone();
			m_shapes.push_back(m);
		}
		m_indexes = m_bar.GetIndexes();
	}
	void ChangeFillColor(sf::Color color) override
	{
		CCommandFillColor(m_bar, color).Execute();
		m_bar.SetStateFillColor();
	}
	void ChangeOutlineColor(sf::Color color) override
	{
		CComandOutlineColor(m_bar, color).Execute();
		m_bar.SetOutlineColor();
	}
	void ChangeThickness(int thick) override
	{
		CCommandThickness(m_bar, thick).Execute();
		m_bar.SetStateThickness();
	}
	void AddFigure(std::vector<IShapeDecorator*>& shapes, std::string name) override
	{
		CCommandAddFigure(m_bar, shapes, name).Execute();
		m_bar.SetStateAddFigure();
	}
	void SetNewPosition(int x, int y)  override
	{
		CCommandNewPosition(m_bar, x, y).Execute();
		m_bar.SetStateDragAndDrop();
	}
	void GroupFigures() override
	{
		CCommandGroupFigures(m_bar).Execute();
		m_bar.SetStateGroupFigures();
	}
	void UngroupFigures() override
	{
		CCommandUngoupFigures(m_bar).Execute();
		m_bar.SetStateUngroupFigures();
	}

private:
	IToolbar& m_bar;
};