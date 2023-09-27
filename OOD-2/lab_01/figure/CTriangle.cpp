
#include "CTriangle.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "CTriangle.h"
#include <string>
#include <math.h>

void CTriangle::Draw(sf::RenderWindow& window) const
{
	sf::ConvexShape shape;
	shape.setFillColor(sf::Color(0xFF, 0, 0xFF));
	shape.setPointCount(3);
	shape.setPoint(0, sf::Vector2f(GetVertex1().GetPointX(), GetVertex1().GetPointY() ));
	shape.setPoint(1, sf::Vector2f(GetVertex2().GetPointX(), GetVertex2().GetPointY() ));
	shape.setPoint(2, sf::Vector2f(GetVertex3().GetPointX(), GetVertex3().GetPointY() ));
	window.draw(shape);
}
std::string CTriangle::GetName() const
{
	return m_name;
}
int CTriangle::GetArea() const
{
	double p = (GetA() + GetB() + GetC()) / 2;
	return sqrt(p * (p - GetA()) * (p - GetB()) * (p - GetC()));
}
int CTriangle::GetPerimeter() const
{
	return GetA() + GetB() + GetC();
}

std::string CTriangle::ToString() const
{
	const std::string TRIANGLE_AREA = "S=";
	const std::string TRIANGLE_PERIMETER = "P=";
	const std::string WHITESPACE = " ";
	//const std::string COMMA = ", ";
	//const std::string TWO_DOTS = ": ";
	return GetName() + WHITESPACE +
		TRIANGLE_AREA + std::to_string(GetArea()) + WHITESPACE +
		TRIANGLE_PERIMETER + std::to_string(GetPerimeter());

}
CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}
CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}
CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

double CTriangle::GetA() const
{
	double x1 = GetVertex1().GetPointX();
	double y1 = GetVertex1().GetPointY();
	double x2 = GetVertex2().GetPointX();
	double y2 = GetVertex2().GetPointY();
	double x2x1 = x2 - x1;
	double y2y1 = y2 - y1;
	double a = sqrt(x2x1 * x2x1 + y2y1 * y2y1);
	return a;
}

double CTriangle::GetB() const
{
	double x2 = GetVertex2().GetPointX();
	double y2 = GetVertex2().GetPointY();
	double x3 = GetVertex3().GetPointX();
	double y3 = GetVertex3().GetPointY();
	double x3x2 = x3 - x2;
	double y3y2 = y3 - y2;
	double b = sqrt(x3x2 * x3x2 + y3y2 * y3y2);
	return b;
}

double CTriangle::GetC() const
{
	double x1 = GetVertex1().GetPointX();
	double y1 = GetVertex1().GetPointY();
	double x3 = GetVertex3().GetPointX();
	double y3 = GetVertex3().GetPointY();
	double x1x3 = x1 - x3;
	double y1y3 = y1 - y3;
	double c = sqrt(x1x3 * x1x3 + y1y3 * y1y3);
	return c;
}