#pragma once
//#include "IStateShapes.h"
//#include "IToolbar.h"
//#include "IShapeDecorator.h"
//#include "CCommandFillColor.h"
#include "CComandOutlineColor.h"
#include "CCommandThickness.h"
#include "CCommandAddFigure.h"
#include "CCommandNewPosition.h"

class CStateAddFigure : public IStateShapes
{
public:
	CStateAddFigure(IToolbar& bar)
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

	std::vector<IShapeDecorator*> GetShapes() override
	{
		return m_shapes;
	}
	std::vector<int> GetIndexes() override
	{
		return m_indexes;
	}
	
private:
	IToolbar& m_bar;
	std::vector<IShapeDecorator*> m_shapes;
	std::vector<int> m_indexes;
};