#define _USE_MATH_DEFINES

#include "CCircleDecorator.h"

//std::string CCircleDecorator::ToString() const
//{
//	const std::string CIRCLE_AREA = "S=";
//	const std::string CIRCLE_PERIMETER = "P=";
//	const std::string WHITESPACE = " ";
//	const std::string COMMA = ", ";
//	const std::string TWO_DOTS = ": ";
//	return GetName() + TWO_DOTS +
//		CIRCLE_AREA + std::to_string(GetArea()) + COMMA +
//		CIRCLE_PERIMETER + std::to_string(GetPerimeter());
//}
double CCircleDecorator::GetShapeArea() const
{
	return M_PI;

}
//double CCircleDecorator::GetPerimeter() const
//{
//	return 2 * M_PI * m_shape.getRadius();
//}
//std::string CCircleDecorator::GetName() const
//{
//	return NAME;
//}
//void CCircleDecorator::Draw(sf::RenderWindow& window) const
//{
//	//sf::CircleShape shape(m_radius);
//	//shape.setPosition(sf::Vector2f(GetCenter().GetPointX(), GetCenter().GetPointY()));
//	//shape.setFillColor(sf::Color(0xFF, 0x0, 0x0));
//	window.draw(m_shape);
//}