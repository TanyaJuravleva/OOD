#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CChangeOutlineColorBlue : public ICommand
{
public:
	CChangeOutlineColorBlue(std::unique_ptr<IShapeDecorator>& figure)
		: m_figure(figure)
	{
	}
	void Execute() override
	{
		m_figure->SetOutlineColor(sf::Color::Blue);
	}
private:
	std::unique_ptr<IShapeDecorator>& m_figure;
};