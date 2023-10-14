//#include "IShapeDecorator.h"
//
//double IShapeDecorator::GetArea() const
//{
//	return GetShapeArea();
//}
//
//double IShapeDecorator::GetPerimeter() const
//{
//	return GetShapePerimeter();
//}
//
//std::string IShapeDecorator::ToString() const
//{
//	const std::string CIRCLE_AREA = "S=";
//	const std::string CIRCLE_PERIMETER = "P=";
//	const std::string WHITESPACE = " ";
//	const std::string COMMA = ", ";
//	const std::string TWO_DOTS = ": ";
//	return GetName() + TWO_DOTS +
//		CIRCLE_AREA + std::to_string(GetArea()) + COMMA +
//		CIRCLE_PERIMETER + std::to_string(GetPerimeter());
//	/*return ToShapeString();*/
//}
//
//std::string IShapeDecorator::GetName() const
//{
//	return GetShapeName();
//}
