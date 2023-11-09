#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CChangeOutlineColorYellow : public ICommand
{
public:
	CChangeOutlineColorYellow(std::unique_ptr<IShapeDecorator>& figure)
		: m_figure(figure)
	{
	}
	void Execute() override
	{
		m_figure->SetOutlineColor(sf::Color::Yellow);
	}
private:
	std::unique_ptr<IShapeDecorator>& m_figure;
};