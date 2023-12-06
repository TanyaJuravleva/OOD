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
	CCommandAddFigure(IToolbar& bar, std::vector<IShapeDecorator*>& shapes, std::string name)
		: m_bar(bar)
		, m_shapes(shapes)
		, m_name(name)
	{
	}
	void Execute() override
	{
		if (m_name == NAME_CIRCLE)
		{
			sf::CircleShape* circle = new sf::CircleShape(20);
			circle->setPosition(0, 0);
			IShapeDecorator* f = new CCircleDecorator(circle);
			m_shapes.push_back(f);
		}
		if (m_name == NAME_RECTANGLE)
		{
			sf::RectangleShape* rec = new sf::RectangleShape;
			rec->setSize(sf::Vector2f(100, 50));
			rec->setPosition(sf::Vector2f(0, 0));
			IShapeDecorator* f = new CRectangleDecorator(rec);
			m_shapes.push_back(f);
		}
		if (m_name == NAME_TRIANGLE)
		{
			sf::ConvexShape* trian = new sf::ConvexShape;
			trian->setPointCount(3);
			trian->setPoint(0, sf::Vector2f(50, 0));
			trian->setPoint(1, sf::Vector2f(100, 50));
			trian->setPoint(2, sf::Vector2f(0, 50));
			IShapeDecorator* f = new CTriangleDecorator(trian);
			m_shapes.push_back(f);
		}
	}
private:
	IToolbar& m_bar;
	std::vector<IShapeDecorator*>& m_shapes;
	std::string m_name;
};