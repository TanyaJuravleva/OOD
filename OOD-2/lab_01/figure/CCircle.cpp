
#define _USE_MATH_DEFINES

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "CCircle.h"
#include <iostream>
#include <cmath>
#include <string>

void CCircle::Draw(sf::RenderWindow& window) const
{
	sf::CircleShape shape(m_radius);
	shape.setPosition(sf::Vector2f(GetCenter().GetPointX(), GetCenter().GetPointY()));
	shape.setFillColor(sf::Color(0xFF, 0x0, 0x0));
	window.draw(shape);
}

std::string CCircle::GetName() const
{
	return m_name;
}

int CCircle::GetArea() const
{
	return int(M_PI * m_radius * m_radius);
}
int CCircle::GetPerimeter() const
{
	return int(2 * M_PI * m_radius);
}

std::string CCircle::ToString() const
{
	const std::string CIRCLE_AREA = "S=";
	const std::string CIRCLE_PERIMETER = "P=";
	const std::string WHITESPACE = " ";
	//const std::string COMMA = ", ";
	//const std::string TWO_DOTS = ": ";
	return GetName() + WHITESPACE +
		CIRCLE_AREA + std::to_string(GetArea()) + WHITESPACE +
		CIRCLE_PERIMETER + std::to_string(GetPerimeter());
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}
int CCircle::GetRadius() const
{
	return m_radius;
}