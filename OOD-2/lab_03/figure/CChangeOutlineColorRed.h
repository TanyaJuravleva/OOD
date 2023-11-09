#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CChangeOutlineColorRed : public ICommand
{
public:
	CChangeOutlineColorRed(std::unique_ptr<IShapeDecorator>& figure)
		: m_figure(figure)
	{
	}
	void Execute() override
	{
		m_figure->SetOutlineColor(sf::Color::Red);
	}
private:
	std::unique_ptr<IShapeDecorator>& m_figure;
};