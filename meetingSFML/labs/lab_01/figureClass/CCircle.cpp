
#define _USE_MATH_DEFINES
#include "CCircle.h"
#include <iostream>
#include <cmath>
#include <string>

std::string CCircle::GetName() const
{
	return "круг";
}

double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}
double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{
	const std::string CIRCLE_AREA = "площадь круга: ";
	const std::string CIRCLE_PERIMETER = "периметр круга: ";
	const std::string CIRCLE_OUTLINE_COLOR = "цвет обводки круга: ";
	const std::string CIRCLE_FILL_COLOR = "цвет заливки круга: ";
	const std::string CIRCLE_CENTER = "координаты центра круга: ";
	const std::string CIRCLE_RADIUS = "радиус круга: ";
	const std::string COMMA = ", ";
	return CIRCLE_AREA + std::to_string(GetArea()) + COMMA + "\n" + "   " +
		   CIRCLE_PERIMETER + std::to_string(GetPerimeter()) + COMMA + "\n" + "   " +
		   CIRCLE_CENTER + std::to_string(GetCenter().GetPointX()) + " " +
		                   std::to_string(GetCenter().GetPointY()) + COMMA + "\n" + "   " +
		   CIRCLE_RADIUS + std::to_string(GetRadius());
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}
double CCircle::GetRadius() const
{
	return m_radius;
}