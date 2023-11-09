#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CChangeOutlineThickness2 : public ICommand
{
public:
	CChangeOutlineThickness2(std::unique_ptr<IShapeDecorator>& figure)
		: m_figure(figure)
	{
	}
	void Execute() override
	{
		m_figure->SetOutlineThickness(2);
	}
private:
	std::unique_ptr<IShapeDecorator>& m_figure;
};