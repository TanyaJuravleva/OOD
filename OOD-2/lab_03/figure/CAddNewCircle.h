#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"

class CAddNewCircle : public ICommand
{
public:
	CAddNewCircle(std::vector<std::unique_ptr<IShapeDecorator>>& shapes)
		: m_shapes(shapes)
	{
	}
	void Execute() override
	{
		auto circle = sf::CircleShape(20);
		circle.setPosition(0, 0);
		auto circlePtr = std::make_unique<sf::CircleShape>(circle);
		m_shapes.emplace_back(std::make_unique<CCircleDecorator>(move(circlePtr)));
	}
private:
	std::vector<std::unique_ptr<IShapeDecorator>>& m_shapes;
};