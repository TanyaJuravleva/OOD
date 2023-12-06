#pragma once

class CShapeOutlineThicknessVisitor
    : public Visitor<const CRectangleDecorator>
    , public Visitor<const CCircleDecorator>
    , public Visitor<const CTriangleDecorator>
    , public Visitor<const CShapeComposite>
    , public IShapeVisitor
{

public:
    CShapeOutlineThicknessVisitor(int thick)
        :m_thick(thick)
    {
    }
    void Visit(const CRectangleDecorator& rectangle) override
    {
        rectangle.GetConcreteFigure()->setOutlineThickness(m_thick);
    }

    void Visit(const CCircleDecorator& circle) override
    {
        circle.GetConcreteFigure()->setOutlineThickness(m_thick);
    }

    virtual void Visit(const CTriangleDecorator& triangle) override
    {
        triangle.GetConcreteFigure()->setOutlineThickness(m_thick);
    }

    void Visit(const CShapeComposite& group) override
    {
        for (size_t i = 0; i < group.GetShapeCount(); ++i)
        {
            group.GetShape(i)->SetOutlineThickness(*this);
        }

    }
private:
    int m_thick;
};
