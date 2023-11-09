#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CChangeOutlineColorGreen : public ICommand
{
public:
	CChangeOutlineColorGreen(std::unique_ptr<IShapeDecorator>& figure)
		: m_figure(figure)
	{
	}
	void Execute() override
	{
		m_figure->SetOutlineColor(sf::Color::Green);
	}
private:
	std::unique_ptr<IShapeDecorator>& m_figure;
};