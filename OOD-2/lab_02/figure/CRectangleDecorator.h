//#pragma once
//#include "IShapeDecorator.h"
//
//const std::string REC_NAME = "RECTANGLE";
//
//class CRectangleDecorator : public IShapeDecorator
//{
//public:
//	CRectangleDecorator(sf::RectangleShape rectangle)
//		: m_rectangle(rectangle)
//	{
//	}
//	std::string ToString() const override;
//	double GetArea() const override;
//	double GetPerimeter() const override;
//	std::string GetName() const override;
//	void Draw(sf::RenderWindow& window) const override;
//
//private:
//	sf::RectangleShape m_rectangle;
//};
//
////m_leftTop(leftTop_x, leftTop_y),
////m_rightBottom(rightBotton_x, rightBotton_y)
//
///*, int leftTop_x, int leftTop_y,
//		int rightBotton_x, int rightBotton_y*/
//		//CPoint GetLeftTop() const;
//		//CPoint GetRightBottom() const;
//		//int GetWidth() const;
//		//int GetHeight() const;
//	//CPoint m_leftTop;
//	//CPoint m_rightBottom;