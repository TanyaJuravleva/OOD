#define _USE_MATH_DEFINES

#include "CRectangleDecorator.h"

std::string CRectangleDecorator::ToString() const
{
	const std::string RECTANGLE_AREA = "S=";
	const std::string RECTANGLE_PERIMETER = "P=";
	const std::string WHITESPACE = " ";
	const std::string COMMA = ", ";
	const std::string TWO_DOTS = ": ";
	return GetName() + TWO_DOTS +
		RECTANGLE_AREA + std::to_string(GetArea()) + COMMA +
		RECTANGLE_PERIMETER + std::to_string(GetPerimeter());
}
double CRectangleDecorator::GetArea() const
{
	return (double)GetWidth() * (double)GetHeight();
}
double CRectangleDecorator::GetPerimeter() const
{
	return 2 * (double)GetWidth() + (double)GetHeight();
}
std::string CRectangleDecorator::GetName() const
{
	return REC_NAME;
}
void CRectangleDecorator::Draw(sf::RenderWindow& window) const
{
	//sf::CircleShape shape(m_radius);
	//shape.setPosition(sf::Vector2f(GetCenter().GetPointX(), GetCenter().GetPointY()));
	//shape.setFillColor(sf::Color(0xFF, 0x0, 0x0));
	window.draw(m_rectangle);
}
CPoint CRectangleDecorator::GetLeftTop() const
{
	return m_leftTop;
}
CPoint CRectangleDecorator::GetRightBottom() const
{
	return m_rightBottom;
}
int CRectangleDecorator::GetWidth() const
{
	return GetRightBottom().GetPointX() - GetLeftTop().GetPointX();
}
int CRectangleDecorator::GetHeight() const
{
	return GetRightBottom().GetPointY() - GetLeftTop().GetPointY();
}