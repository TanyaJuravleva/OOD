#pragma once
#include "IBuilderShape.h"
#include "CCircleDecorator.h"
#include "CShapeFillColorVisitor.h"
#include "CShapeOutlineColorVisitor.h"
#include "CShapeOutlineThicknessVisitor.h"

class CBuilderCirlce : public IBuilderShape 
{
private:
    IShapeDecorator* product;
public:

    CBuilderCirlce(int r) 
    {
        this->Reset(r);
    }
    ~CBuilderCirlce() {
        delete product;
    }

    void Reset(int r) {
        sf::CircleShape* circle = new sf::CircleShape(r);
        this->product = new CCircleDecorator(circle);
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