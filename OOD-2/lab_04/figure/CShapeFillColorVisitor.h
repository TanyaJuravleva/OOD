#pragma once
#include "IShapeVisitor.h"
//#include "CCircleDecorator.h"
//#include "CRectangleDecorator.h"
//#include "CTriangleDecorator.h"
#include "CShapeComposite.h"

//class CShapeFillColorVisitor : public IShapeVisitor
//{
//	sf::Color m_color;
//public:
//	CShapeFillColorVisitor(sf::Color color) 
//		:m_color(color)
//	{
//	}
//	void Visit(std::unique_ptr < sf::RectangleShape>& rectangle) override
//	{
//		rectangle->setFillColor(m_color);
//	}
//	void Visit(std::unique_ptr<sf::CircleShape>& circle) override
//	{
//		circle->setFillColor(m_color);
//	}
//	virtual void Visit(std::unique_ptr<sf::ConvexShape>& triangle) override
//	{
//		triangle->setFillColor(m_color);
//	}
//	void Visit(CShapeComposite& group) override
//	{
//		//for (int i = 0; i < group.size(); i++)
//		//{
//		//	auto m = this->get;
//		//	group[i]->SetFillColor(*this->get());
//		//}
//	}
//};

class CShapeFillColorVisitor
    : public Visitor<const CRectangleDecorator>
    , public Visitor<const CCircleDecorator>
    , public Visitor<const CTriangleDecorator>
    , public Visitor<const CShapeComposite>
    , public IShapeVisitor
{

public:
    CShapeFillColorVisitor(sf::Color color) 
    	:m_color(color)
    {
    }
    void Visit(const CRectangleDecorator& rectangle) override
    {
        rectangle.GetConcreteFigure()->setFillColor(m_color);
    }

    void Visit(const CCircleDecorator& circle) override
    {
        circle.GetConcreteFigure()->setFillColor(m_color);
    }

    virtual void Visit(const CTriangleDecorator& triangle) override
    {
        triangle.GetConcreteFigure()->setFillColor(m_color);
    }

    void Visit(const CShapeComposite& group) override
    {
        for (size_t i = 0; i < group.GetShapeCount(); ++i)
        {
            group.GetShape(i)->SetFillColor(*this);
        }

    }
private:
    sf::Color m_color;
};
