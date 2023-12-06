#pragma once
#include "IRecoverTemplate.h"
#include "IShapeDecorator.h"
#include "CBuilderCirlce.h"
#include "CBuilderRectangle.h"
#include "CBuilderTriangele.h"
#include "CBuilderGroup.h"
#include "CCreateFigureTemplate.h"
#include "IBuilderShape.h"
#include <fstream>
std::string GetColorName3(sf::Color color)
{
	if (color == sf::Color::Blue)
		return "blue";
	if (color == sf::Color::Red)
		return "red";
	if (color == sf::Color::Yellow)
		return "yellow";
	if (color == sf::Color::Green)
		return "green";
	if (color == sf::Color::White)
		return "white";
}
sf::Color GetColorByName3(std::string color)
{
	if (color == "blue")
		return sf::Color::Blue;
	if (color == "red")
		return sf::Color::Red;
	if (color == "red")
		return sf::Color::Yellow;
	if (color == "green")
		return sf::Color::Green;
	if (color == "white")
		return sf::Color::White;
}

class CRecoverFromTxt : public IRecoverTemplate
{
	void ReadFile() override
	{
		
		IShapeDecorator* shape;
		std::string figureName = "jhk";
		std::ifstream inp("figures.txt");
		float recWidth, recHeight;
		float vertex1_x, vertex1_y,
			vertex2_x, vertex2_y,
			vertex3_x, vertex3_y;
		float radius;
		float posX, posY;
		std::string colorFill, colorOutline;
		float thick;
		CCreateFigureTemplate creatorShape;
		IBuilderShape* builderShape;
		while (inp >> figureName)
		{
			if (figureName == "RECTANGLE")
			{
				inp >> recWidth >> recHeight >> posX >> posY >> colorFill >> colorOutline >> thick;
				builderShape = new CBuilderRectangle(recWidth, recHeight);
				shape = creatorShape.CreateFigure(builderShape, posX, posY, GetColorByName3(colorFill), GetColorByName3(colorOutline), thick);
				arr.push_back(shape);
			}

			if (figureName == "TRIANGLE")
			{
				inp >> vertex1_x >> vertex1_y >> vertex2_x >> vertex2_y >> vertex3_x >> vertex3_y >> posX >> posY >> colorFill >> colorOutline >> thick;
				IBuilderShape* builderShape = new CBuilderTriangele(vertex1_x, vertex1_y, vertex2_x, vertex2_y, vertex3_x, vertex3_y);
				shape = creatorShape.CreateFigure(builderShape, posX, posY, GetColorByName3(colorFill), GetColorByName3(colorOutline), thick);
				arr.push_back(shape);
			}

			if (figureName == "CIRCLE")
			{
				inp >> radius >> posX >> posY >> colorFill >> colorOutline >> thick;
				IBuilderShape* builderShape = new CBuilderCirlce(radius);
				shape = creatorShape.CreateFigure(builderShape, posX, posY, GetColorByName3(colorFill), GetColorByName3(colorOutline), thick);
				arr.push_back(shape);
			}
		}
		inp.close();
	}
};