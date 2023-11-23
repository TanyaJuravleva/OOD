#pragma once
#include "IStateShapes.h"
#include "IToolbar.h"
#include "IShapeDecorator.h"
#include "CCommandFillColor.h"
#include "CComandOutlineColor.h"
#include "CCommandThickness.h"
#include "CCommandAddFigure.h"

class CStateDragAndDrop : public IStateShapes
{
public:
	CStateDragAndDrop(IToolbar& bar)
		: m_bar(bar)
	{
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
	virtual void ChangeThickness(int thick)
	{
		CCommandThickness(m_bar, thick).Execute();
		m_bar.SetStateThickness();
	}
	virtual void AddFigure(std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::string name)
	{
		CCommandAddFigure(m_bar, shapes, name).Execute();
		m_bar.SetStateDragAndDrop();
	}
	
private:
	IToolbar& m_bar;
};