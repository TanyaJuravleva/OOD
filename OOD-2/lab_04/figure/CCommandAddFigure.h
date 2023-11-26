#pragma once
//#include "ICommand.h"
//#include "IShapeDecorator.h"
//#include "IToolbar.h"
//#include "CCircleDecorator.h"
//#include "CRectangleDecorator.h"
//#include "CTriangleDecorator.h"

class CCommandAddFigure : public ICommand
{
public:
	CCommandAddFigure(IToolbar& bar, std::vector<std::unique_ptr<IShapeDecorator>>& shapes, std::string name)
		: m_bar(bar)
		, m_shapes(shapes)
		, m_name(name)
	{
	}
	void Execute() override
	{
		if (m_name == "circle")
		{
			auto circle = sf::CircleShape(20);
			circle.setPosition(0, 0);
			auto circlePtr = std::make_unique<sf::CircleShape>(circle);
			m_shapes.emplace_back(std::make_unique<CCircleDecorator>(move(circlePtr)));
			//m_shapes.emplace_back(std::make_unique<CCircleDecorator>(20, 20, 20));
		}
		if (m_name == "rectangle")
		{
			sf::RectangleShape rec;
			rec.setSize(sf::Vector2f(100, 50));
			rec.setPosition(sf::Vector2f(0, 0));
			auto recPtr = std::make_unique<sf::RectangleShape>(rec);
			m_shapes.emplace_back(std::make_unique<CRectangleDecorator>(move(recPtr)));
		}
		if (m_name == "triangle")
		{
			sf::ConvexShape trian;
			trian.setPointCount(3);
			trian.setPoint(0, sf::Vector2f(50, 0));
			trian.setPoint(1, sf::Vector2f(100, 50));
			trian.setPoint(2, sf::Vector2f(0, 50));
			auto trianPtr = std::make_unique<sf::ConvexShape>(trian);
			m_shapes.emplace_back(std::make_unique <CTriangleDecorator>(move(trianPtr)));
		}
	}
private:
	IToolbar& m_bar;
	std::vector<std::unique_ptr<IShapeDecorator>>& m_shapes;
	std::string m_name;
};