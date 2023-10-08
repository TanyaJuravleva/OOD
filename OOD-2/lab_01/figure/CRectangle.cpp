#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "CRectangle.h"
#include <iostream>
#include <string>

void CRectangle::Draw(sf::RenderWindow& window) const
{
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f( GetWidth(),GetHeight() ));
	shape.setPosition(sf::Vector2f(GetRightBottom().GetPointX() - GetWidth()/ 2,
		GetRightBottom().GetPointY() - GetHeight() / 2 ));
	shape.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
	window.draw(shape);
}

std::string CRectangle::GetName() const
{
	return m_name;
}

int CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}
int CRectangle::GetPerimeter() const
{
	return 2 * (GetWidth() + GetHeight());
}
std::string CRectangle::ToString() const
{
	const std::string RECTANGLE_AREA = "S=";
	const std::string RECTANGLE_PERIMETER = "P=";
	const std::string WHITESPACE = " ";
	//const std::string COMMA = ", ";
	//const std::string TWO_DOTS = ": ";
	return GetName() + WHITESPACE +
		RECTANGLE_AREA + std::to_string(GetArea()) + WHITESPACE + 
		RECTANGLE_PERIMETER + std::to_string(GetPerimeter());
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}
CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}
int CRectangle::GetWidth() const
{
	return GetRightBottom().GetPointX() - GetLeftTop().GetPointX();
}
int CRectangle::GetHeight() const
{
	return GetRightBottom().GetPointY() - GetLeftTop().GetPointY() ;
}