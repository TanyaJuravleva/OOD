#pragma once
#include "IBuilderShape.h"
#include "CShapeComposite.h"
#include "CShapeFillColorVisitor.h"
#include "CShapeOutlineColorVisitor.h"
#include "CShapeOutlineThicknessVisitor.h"

class CBuilderGroup : public IBuilderShape
{
private:
    IShapeDecorator* product;
public:

    CBuilderGroup()
    {
        this->Reset();
    }
    ~CBuilderGroup() {
        delete product;
    }

    void Reset() {
        this->product = new CShapeComposite();
    }

    void ProduceCommon() override
    {
        return;
    }
    void ProducePosition(int x, int y)
    {
        return;
    }
    void ProduceFillColor(sf::Color color)
    {
        return;
    }
    void ProduceOutlineColor(sf::Color color)
    {
        return;
    }
    void ProduceOutlineThickness(int thickness)
    {
        return;
    }

    IShapeDecorator* GetProduct() override
    {
        return this->product;
    }
};