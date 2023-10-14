//#include "CTriangleDecorator.h"
//
//void CTriangleDecorator::Draw(sf::RenderWindow& window) const
//{
//	window.draw(m_triangle);
//}
//std::string CTriangleDecorator::GetName() const
//{
//	return TRIAN_NAME;
//}
//double CTriangleDecorator::GetArea() const
//{
//	double p = (GetA() + GetB() + GetC()) / 2;
//	return sqrt(p * (p - GetA()) * (p - GetB()) * (p - GetC()));
//}
//double CTriangleDecorator::GetPerimeter() const
//{
//	return GetA() + GetB() + GetC();
//}
//
//std::string CTriangleDecorator::ToString() const
//{
//	const std::string TRIANGLE_AREA = "S=";
//	const std::string TRIANGLE_PERIMETER = "P=";
//	const std::string WHITESPACE = " ";
//	const std::string COMMA = ", ";
//	const std::string TWO_DOTS = ": ";
//	return GetName() + TWO_DOTS +
//		TRIANGLE_AREA + std::to_string(GetArea()) + COMMA +
//		TRIANGLE_PERIMETER + std::to_string(GetPerimeter());
//
//}
//
//double CTriangleDecorator::GetA() const
//{
//	auto point1 = m_triangle.getPoint(0);
//	auto point2 = m_triangle.getPoint(1);
//	double x1 = point1.x;
//	double y1 = point1.y;
//	double x2 = point2.x;
//	double y2 = point2.y;
//	double x2x1 = x2 - x1;
//	double y2y1 = y2 - y1;
//	double a = sqrt(x2x1 * x2x1 + y2y1 * y2y1);
//	return a;
//}
//
//double CTriangleDecorator::GetB() const
//{
//	auto point2 = m_triangle.getPoint(1);
//	auto point3 = m_triangle.getPoint(2);
//	double x2 = point2.x;
//	double y2 = point2.y;
//	double x3 = point3.x;
//	double y3 = point3.y;
//	double x3x2 = x3 - x2;
//	double y3y2 = y3 - y2;
//	double b = sqrt(x3x2 * x3x2 + y3y2 * y3y2);
//	return b;
//}
//
//double CTriangleDecorator::GetC() const
//{
//	auto point1 = m_triangle.getPoint(0);
//	auto point3 = m_triangle.getPoint(2);
//	double x1 = point1.x;
//	double y1 = point1.y;
//	double x3 = point3.x;
//	double y3 = point3.y;
//	double x1x3 = x1 - x3;
//	double y1y3 = y1 - y3;
//	double c = sqrt(x1x3 * x1x3 + y1y3 * y1y3);
//	return c;
//}
//
////CPoint CTriangleDecorator::GetVertex1() const
////{
////	return m_vertex1;
////}
////CPoint CTriangleDecorator::GetVertex2() const
////{
////	return m_vertex2;
////}
////CPoint CTriangleDecorator::GetVertex3() const
////{
////	return m_vertex3;
////}