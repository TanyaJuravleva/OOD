#pragma once
#include "ICommand.h"
#include "IShapeDecorator.h"
#include "CTriangleDecorator.h"

class CAddNewTriangle : public ICommand
{
public:
	CAddNewTriangle(std::vector<std::unique_ptr<IShapeDecorator>>& shapes)
		: m_shapes(shapes)
	{
	}
	void Execute() override
	{
		sf::ConvexShape trian;
		trian.setPointCount(3);
		trian.setPoint(0, sf::Vector2f(50, 0));
		trian.setPoint(1, sf::Vector2f(100, 50));
		trian.setPoint(2, sf::Vector2f(0, 50));
		auto trianPtr = std::make_unique<sf::ConvexShape>(trian);
		m_shapes.emplace_back(std::make_unique <CTriangleDecorator>(move(trianPtr)));
	}
private:
	std::vector<std::unique_ptr<IShapeDecorator>>& m_shapes;
};