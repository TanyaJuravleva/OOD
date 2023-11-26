#pragma once
#include "IShapeVisitor.h"
#include "CShapeComposite.h"

class CShapeOutlineColorVisitor
    : public Visitor<const CRectangleDecorator>
    , public Visitor<const CCircleDecorator>
    , public Visitor<const CTriangleDecorator>
    , public Visitor<const CShapeComposite>
    , public IShapeVisitor
{

public:
    CShapeOutlineColorVisitor(sf::Color color)
        :m_color(color)
    {
    }
    void Visit(const CRectangleDecorator& rectangle) override
    {
        rectangle.GetConcreteFigure()->setOutlineColor(m_color);
    }

    void Visit(const CCircleDecorator& circle) override
    {
        circle.GetConcreteFigure()->setOutlineColor(m_color);
    }

    virtual void Visit(const CTriangleDecorator& triangle) override
    {
        triangle.GetConcreteFigure()->setOutlineColor(m_color);
    }

    void Visit(const CShapeComposite& group) override
    {
        for (size_t i = 0; i < group.GetShapeCount(); ++i)
        {
            group.GetShape(i)->SetOutlineColor(*this);
        }

    }
private:
    sf::Color m_color;
};
