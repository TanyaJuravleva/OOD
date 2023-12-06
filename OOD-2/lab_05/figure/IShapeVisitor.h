#pragma once

class IShapeVisitor
{
public:
	virtual ~IShapeVisitor() = default;
};

template <typename Visitable>
class Visitor
{
public:
	virtual void Visit(Visitable&) = 0;
};


//#include "IShapeDecorator.h"
//#include "CCircleDecorator.h"
//#include "CRectangleDecorator.h"
//#include "CTriangleDecorator.h"
//#include "CShapeComposite.h"

//class IShapeVisitor
//{
//public:
//	virtual void Visit(std::unique_ptr<sf::RectangleShape>& rectangle) = 0;
//	virtual void Visit(std::unique_ptr<sf::CircleShape>& circle) = 0;
//	virtual void Visit(std::unique_ptr<sf::ConvexShape>& triangle) = 0;
//	virtual void Visit(CShapeComposite& group) = 0;
//	virtual ~IShapeVisitor() = default;
//};

//virtual void Visit(std::unique_ptr<sf::RectangleShape>& rectangle) = 0;
//virtual void Visit(std::unique_ptr<sf::CircleShape>& circle) = 0;
//virtual void Visit(std::unique_ptr<sf::ConvexShape>& triangle) = 0;