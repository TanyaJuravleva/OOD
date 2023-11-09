#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CChangeFillColourGreen : public ICommand
{
public:
	CChangeFillColourGreen(std::unique_ptr<IShapeDecorator>& figure)
		: m_figure(figure)
	{
	}
	void Execute() override
	{
		m_figure->SetFillColour(sf::Color::Green);
	}
private:
	std::unique_ptr<IShapeDecorator>& m_figure;
};