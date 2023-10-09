#define _USE_MATH_DEFINES

#include "CCircleDecorator.h"

std::string CCircleDecorator::ToString() const
{
	const std::string CIRCLE_AREA = "S=";
	const std::string CIRCLE_PERIMETER = "P=";
	const std::string WHITESPACE = " ";
	const std::string COMMA = ", ";
	const std::string TWO_DOTS = ": ";
	return GetName() + TWO_DOTS +
		CIRCLE_AREA + std::to_string(GetArea()) + COMMA +
		CIRCLE_PERIMETER + std::to_string(GetPerimeter());
}
double CCircleDecorator::GetArea() const
{
	return M_PI * m_circle.getRadius() * m_circle.getRadius();

}
double CCircleDecorator::GetPerimeter() const
{
	return 2 * M_PI * m_circle.getRadius();
}
std::string CCircleDecorator::GetName() const
{
	return CIRCLE_NAME;
}
void CCircleDecorator::Draw(sf::RenderWindow& window) const
{
	window.draw(m_circle);
}