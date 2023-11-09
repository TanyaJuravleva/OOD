#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CChangeOutlineThickness4 : public ICommand
{
public:
	CChangeOutlineThickness4(std::unique_ptr<IShapeDecorator>& figure)
		: m_figure(figure)
	{
	}
	void Execute() override
	{
		m_figure->SetOutlineThickness(4);
	}
private:
	std::unique_ptr<IShapeDecorator>& m_figure;
};