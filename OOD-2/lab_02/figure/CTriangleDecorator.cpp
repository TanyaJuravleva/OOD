#include "CTriangleDecorator.h"

void CTriangleDecorator::Draw(sf::RenderWindow& window) const
{
	//sf::ConvexShape shape;
	//shape.setFillColor(sf::Color(0xFF, 0, 0xFF));
	//shape.setPointCount(3);
	//shape.setPoint(0, sf::Vector2f(GetVertex1().GetPointX(), GetVertex1().GetPointY()));
	//shape.setPoint(1, sf::Vector2f(GetVertex2().GetPointX(), GetVertex2().GetPointY()));
	//shape.setPoint(2, sf::Vector2f(GetVertex3().GetPointX(), GetVertex3().GetPointY()));
	window.draw(m_triangle);
}
std::string CTriangleDecorator::GetName() const
{
	return TRIAN_NAME;
}
double CTriangleDecorator::GetArea() const
{
	double p = (GetA() + GetB() + GetC()) / 2;
	return sqrt(p * (p - GetA()) * (p - GetB()) * (p - GetC()));
}
double CTriangleDecorator::GetPerimeter() const
{
	return GetA() + GetB() + GetC();
}

std::string CTriangleDecorator::ToString() const
{
	const std::string TRIANGLE_AREA = "S=";
	const std::string TRIANGLE_PERIMETER = "P=";
	const std::string WHITESPACE = " ";
	const std::string COMMA = ", ";
	const std::string TWO_DOTS = ": ";
	return GetName() + TWO_DOTS +
		TRIANGLE_AREA + std::to_string(GetArea()) + COMMA +
		TRIANGLE_PERIMETER + std::to_string(GetPerimeter());

}
CPoint CTriangleDecorator::GetVertex1() const
{
	return m_vertex1;
}
CPoint CTriangleDecorator::GetVertex2() const
{
	return m_vertex2;
}
CPoint CTriangleDecorator::GetVertex3() const
{
	return m_vertex3;
}

double CTriangleDecorator::GetA() const
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

double CTriangleDecorator::GetB() const
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

double CTriangleDecorator::GetC() const
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