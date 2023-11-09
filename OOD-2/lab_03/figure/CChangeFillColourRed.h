#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CChangeFillColourRed : public ICommand
{
public:
	CChangeFillColourRed(std::unique_ptr<IShapeDecorator>& figure)
		: m_figure(figure)
	{
	}
    void Execute() override;
private:
    std::unique_ptr<IShapeDecorator>& m_figure;
};