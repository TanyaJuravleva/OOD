#pragma once
#pragma once
#include "IBuilderShape.h"
#include "CTriangleDecorator.h"
#include "CShapeFillColorVisitor.h"
#include "CShapeOutlineColorVisitor.h"
#include "CShapeOutlineThicknessVisitor.h"

class CBuilderTriangele : public IBuilderShape
{
private:
    IShapeDecorator* product;
public:

    CBuilderTriangele(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        this->Reset(x1, y1, x2, y2, x3, y3);
    }
    ~CBuilderTriangele() {
        delete product;
    }

    void Reset(int x1, int y1, int x2, int y2, int x3, int y3) {
        sf::ConvexShape* trian = new sf::ConvexShape;
        trian->setPointCount(3);
        trian->setPoint(0, sf::Vector2f(x1, y1));
        trian->setPoint(1, sf::Vector2f(x2, y2));
        trian->setPoint(2, sf::Vector2f(x3, y3));
        this->product = new CTriangleDecorator(trian);
    }

    void ProduceCommon() override
    {
        return;
    }
    void ProducePosition(int x, int y)
    {
        this->product->SetPosition(x, y);
    }
    void ProduceFillColor(sf::Color color)
    {
        CShapeFillColorVisitor visitor(color);
        this->product->SetFillColor(visitor);
    }
    void ProduceOutlineColor(sf::Color color)
    {
        CShapeOutlineColorVisitor visitor(color);
        this->product->SetOutlineColor(visitor);
    }
    void ProduceOutlineThickness(int thickness)
    {
        CShapeOutlineThicknessVisitor visitor(thickness);
        this->product->SetOutlineThickness(visitor);
    }

    IShapeDecorator* GetProduct() override
    {
        return this->product;
    }
};