#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"
#include "CRectangleDecorator.h"

class CAddNewRectangle : public ICommand
{
public:
	CAddNewRectangle(std::vector<std::unique_ptr<IShapeDecorator>>& shapes)
		: m_shapes(shapes)
	{
	}
	void Execute() override
	{
		sf::RectangleShape rec;
		rec.setSize(sf::Vector2f(100, 50));
		rec.setPosition(sf::Vector2f(0, 0));
		auto recPtr = std::make_unique<sf::RectangleShape>(rec);
		m_shapes.emplace_back(std::make_unique<CRectangleDecorator>(move(recPtr)));
	}
private:
	std::vector<std::unique_ptr<IShapeDecorator>>& m_shapes;
};