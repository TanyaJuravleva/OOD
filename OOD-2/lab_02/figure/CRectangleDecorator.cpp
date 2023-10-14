//#define _USE_MATH_DEFINES
//
//#include "CRectangleDecorator.h"
//
//std::string CRectangleDecorator::ToString() const
//{
//	const std::string RECTANGLE_AREA = "S=";
//	const std::string RECTANGLE_PERIMETER = "P=";
//	const std::string WHITESPACE = " ";
//	const std::string COMMA = ", ";
//	const std::string TWO_DOTS = ": ";
//	return GetName() + TWO_DOTS +
//		RECTANGLE_AREA + std::to_string(GetArea()) + COMMA +
//		RECTANGLE_PERIMETER + std::to_string(GetPerimeter());
//}
//double CRectangleDecorator::GetArea() const
//{
//	auto size = m_rectangle.getSize();
//	return (double)size.x * (double)size.y;
//}
//double CRectangleDecorator::GetPerimeter() const
//{
//	auto size = m_rectangle.getSize();
//	return 2 * ((double)size.x + (double)size.y);
//}
//std::string CRectangleDecorator::GetName() const
//{
//	return REC_NAME;
//}
//void CRectangleDecorator::Draw(sf::RenderWindow& window) const
//{
//	window.draw(m_rectangle);
//}
////CPoint CRectangleDecorator::GetLeftTop() const
////{
////	return m_leftTop;
////}
////CPoint CRectangleDecorator::GetRightBottom() const
////{
////	return m_rightBottom;
////}
////int CRectangleDecorator::GetWidth() const
////{
////	return GetRightBottom().GetPointX() - GetLeftTop().GetPointX();
////}
////int CRectangleDecorator::GetHeight() const
////{
////	return GetRightBottom().GetPointY() - GetLeftTop().GetPointY();
////}
//
//	/*return (double)GetWidth() * (double)GetHeight();*/
//	/*return 2 * (double)GetWidth() + (double)GetHeight();*/