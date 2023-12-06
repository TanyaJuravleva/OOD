#pragma once
#include "IShapeDecorator.h"
#include "IBuilderShape.h"
#include "ReverseColor.h"
#include "CONSTS.h"

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
	IShapeDecorator* CreateGroup(CBuilderGroup* builder, std::ifstream& file)
	{
		std::string figureName;
		IShapeDecorator* shape = nullptr;
		CCreateFigureTemplate creatorShape;
		int grCount = 1;
		while (file >> figureName)
		{
			shape = GetShape(figureName, file);
			if (figureName == START_GROUP)
			{
				grCount += 1;
				CBuilderGroup* builderShape = new CBuilderGroup();
				shape = CreateGroup(builderShape, file);
			}
			if (figureName == END_GROUP)
			{
				grCount -= 1;
				continue;
			}
			if (grCount == 0)
				break;
			builder->Add(shape);
		}
		return builder->GetProduct();
	}
	IShapeDecorator* GetShape(std::string figureName, std::ifstream& file)
	{
		IShapeDecorator* shape = nullptr;
		float recWidth, recHeight;
		float vertex1_x, vertex1_y,
			vertex2_x, vertex2_y,
			vertex3_x, vertex3_y;
		float radius;
		float posX, posY;
		std::string colorFill, colorOutline;
		float thick;
		IBuilderShape* builderShape;
		if (figureName == NAME_RECTANGLE)
		{
			file >> recWidth >> recHeight >> posX >> posY >> colorFill >> colorOutline >> thick;
			builderShape = new CBuilderRectangle(recWidth, recHeight);
			shape = CreateFigure(builderShape, posX, posY, GetColorByName(colorFill), GetColorByName(colorOutline), thick);
		}

		if (figureName == NAME_TRIANGLE)
		{
			file >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >> vertex3_x >> vertex3_y >> posX >> posY >> colorFill >> colorOutline >> thick;
			builderShape = new CBuilderTriangele(vertex1_x, vertex1_y, vertex2_x, vertex2_y, vertex3_x, vertex3_y);
			shape = CreateFigure(builderShape, posX, posY, GetColorByName(colorFill), GetColorByName(colorOutline), thick);
		}

		if (figureName == NAME_CIRCLE)
		{
			file >> radius >> posX >> posY >> colorFill >> colorOutline >> thick;
			builderShape = new CBuilderCirlce(radius);
			shape = CreateFigure(builderShape, posX, posY, GetColorByName(colorFill), GetColorByName(colorOutline), thick);
		}
		return shape;
	}
};