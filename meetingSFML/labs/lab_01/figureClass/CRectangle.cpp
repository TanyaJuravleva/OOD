#include "CRectangle.h"
#include <iostream>
#include <string>


std::string CRectangle::GetName() const
{
	return "прямоугольник";
}

double CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}
double CRectangle::GetPerimeter() const
{
	return 2 * (GetWidth() + GetHeight());
}
std::string CRectangle::ToString() const
{
	const std::string RECTANGLE_AREA = "площадь прямоугольника: ";
	const std::string RECTANGLE_PERIMETER = "периметр прямоугольника: ";
	const std::string RECTANGLE_OUTLINE_COLOR = "цвет обводки прямоугольника: ";
	const std::string RECTANGLE_FILL_COLOR = "цвет заливки прямоугольника: ";
	const std::string RECTANGLE_LEFT_TOP = "координаты левого верхего угла прямоугольника: ";
	const std::string RECTANGLE_RIGHT_BOTTOM = "координаты правого нижнего угла прямоугольника: ";
	const std::string RECTANGLE_WIDTH = "ширина прямоугольника: ";
	const std::string RECTANGLE_HEIGHT = "высота прямоугольника: ";
	const std::string COMMA = ", ";
	return RECTANGLE_AREA + std::to_string(GetArea()) + COMMA + "\n" + "   " +
		RECTANGLE_PERIMETER + std::to_string(GetPerimeter()) + COMMA + "\n" + "   " +
		RECTANGLE_LEFT_TOP + std::to_string(GetLeftTop().GetPointX()) + " " +
		                     std::to_string(GetLeftTop().GetPointY()) + COMMA + "\n" + "   " +
		RECTANGLE_RIGHT_BOTTOM + std::to_string(GetRightBottom().GetPointX()) + " " +
							 std::to_string(GetRightBottom().GetPointY()) + COMMA + "\n" + "   " +
		RECTANGLE_WIDTH + std::to_string(GetWidth()) + COMMA + "\n" + "   " +
		RECTANGLE_HEIGHT + std::to_string(GetHeight());
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}
CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}
double CRectangle::GetWidth() const
{
	return GetRightBottom().GetPointX() - GetLeftTop().GetPointX();
}
double CRectangle::GetHeight() const
{
	return  GetLeftTop().GetPointY() - GetRightBottom().GetPointY();
}