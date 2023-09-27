
#include "CTriangle.h"
#include <iostream>
#include <string>
#include <math.h>

std::string CTriangle::GetName() const
{
	return "треугольник";
}
double CTriangle::GetArea() const
{
	double p = (GetA() + GetB() + GetC()) / 2;
	return sqrt(p * (p - GetA()) * (p - GetB()) * (p - GetC()));
}
double CTriangle::GetPerimeter() const
{
	return GetA() + GetB() + GetC();
}

std::string CTriangle::ToString() const
{
	const std::string TRIANGLE_AREA = "площадь треугольника: ";
	const std::string TRIANGLE_PERIMETER = "периметр треугольника: ";
	const std::string TRIANGLE_OUTLINE_COLOR = "цвет обводки треугольника: ";
	const std::string TRIANGLE_FILL_COLOR = "цвет заливки треугольника: ";
	const std::string TRIANGLE_VERTEX1 = "координаты первого угла треугольника: ";
	const std::string TRIANGLE_VERTEX2 = "координаты второго угла треугольника: ";
	const std::string TRIANGLE_VERTEX3 = "координаты третьего угла треугольника: ";
	const std::string TRIANGLE_A = "сторона a треугольника: ";
	const std::string TRIANGLE_B = "сторона b треугольника: ";
	const std::string TRIANGLE_C = "сторона c треугольника: ";
	const std::string COMMA = ", ";
	return TRIANGLE_AREA + std::to_string(GetArea()) + COMMA + "\n" + "   " +
		TRIANGLE_PERIMETER + std::to_string(GetPerimeter()) + COMMA + "\n" + "   " +
		TRIANGLE_VERTEX1 + std::to_string(GetVertex1().GetPointX()) + " " +
						   std::to_string(GetVertex1().GetPointY()) + COMMA + "\n" + "   " +
		TRIANGLE_VERTEX2 + std::to_string(GetVertex2().GetPointX()) + " " +
		                   std::to_string(GetVertex2().GetPointY()) + COMMA + "\n" + "   " +
		TRIANGLE_VERTEX3 + std::to_string(GetVertex3().GetPointX()) + " " +
		                   std::to_string(GetVertex3().GetPointY()) + COMMA + "\n" + "   " +
		TRIANGLE_A + std::to_string(GetA()) + " " + COMMA + "\n" + "   " +
		TRIANGLE_B + std::to_string(GetB()) + " " + COMMA + "\n" + "   " +
		TRIANGLE_C + std::to_string(GetC());
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