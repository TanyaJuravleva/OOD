#pragma once
#include "IShapeDecorator.h"

class IBuilderShape
{
public:
    virtual ~IBuilderShape() {}
    virtual void ProduceCommon() = 0;
    virtual void ProducePosition(int x, int y) = 0;
    virtual void ProduceFillColor(sf::Color color) = 0;
    virtual void ProduceOutlineColor(sf::Color color) = 0;
    virtual void ProduceOutlineThickness(int thickness) = 0;
    virtual IShapeDecorator* GetProduct() = 0;
};