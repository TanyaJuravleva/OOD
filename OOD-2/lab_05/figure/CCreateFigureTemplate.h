#pragma once
#include "IShapeDecorator.h"
#include "IBuilderShape.h"

class CCreateFigureTemplate
{
public:
	IShapeDecorator* CreateFigure(IBuilderShape* builder, int x, int y, sf::Color fillColor, sf::Color OutColor, int thick)
	{
		builder->ProducePosition(x, y);
		builder->ProduceFillColor(fillColor);
		builder->ProduceOutlineColor(OutColor);
		builder->ProduceOutlineThickness(thick);
		return builder->GetProduct();
	}
};