#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CChangeFillColourBlue : public ICommand
{
public:
	CChangeFillColourBlue(std::unique_ptr<IShapeDecorator>& figure)
		: m_figure(figure)
	{
	}
	void Execute() override
	{
		m_figure->SetFillColour(sf::Color::Blue);
	}
private:
	std::unique_ptr<IShapeDecorator>& m_figure;
};