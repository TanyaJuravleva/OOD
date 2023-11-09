#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CChangeFillColourYellow : public ICommand
{
public:
	CChangeFillColourYellow(std::unique_ptr<IShapeDecorator>& figure)
		: m_figure(figure)
	{
	}
	void Execute() override
	{
		m_figure->SetFillColour(sf::Color::Yellow);
	}
private:
	std::unique_ptr<IShapeDecorator>& m_figure;
};