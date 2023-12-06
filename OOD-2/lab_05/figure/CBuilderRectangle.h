#pragma once
#pragma once
#include "IBuilderShape.h"
#include "CRectangleDecorator.h"
#include "CShapeFillColorVisitor.h"
#include "CShapeOutlineColorVisitor.h"
#include "CShapeOutlineThicknessVisitor.h"

class CBuilderRectangle : public IBuilderShape
{
private:
    IShapeDecorator* product;
public:

    CBuilderRectangle(int width, int height)
    {
        this->Reset(width, height);
    }
    ~CBuilderRectangle() {
        delete product;
    }

    void Reset(int width, int height) {
        sf::RectangleShape* rec = new sf::RectangleShape;
        rec->setSize(sf::Vector2f(width, height));
        this->product = new CRectangleDecorator(rec);
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