#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"
#include "IToolbar.h"

class CCommandFillColor : public ICommand
{
public:
	CCommandFillColor(IToolbar& bar, sf::Color color)
		: m_bar(bar)
		, m_color(color)
	{
	}
	void Execute() override
	{
		auto arrInd = m_bar.GetIndexes();
		for (int i = 0; i < arrInd.size(); i++)
		{
			m_bar.GetShapes()[arrInd[i]]->SetFillColour(m_color);
		}
	}
private:
	IToolbar& m_bar;
	sf::Color m_color;
};