#pragma once
#include "IShapeDecorator.h"
#include "CPoint.h"

const std::string REC_NAME = "RECTANGLE";

class CRectangleDecorator : public IShapeDecorator
{
public:
	CRectangleDecorator(sf::RectangleShape rectangle, int leftTop_x, int leftTop_y,
		int rightBotton_x, int rightBotton_y)
		: m_rectangle(rectangle),
		m_leftTop(leftTop_x, leftTop_y),
		m_rightBottom(rightBotton_x, rightBotton_y)
	{
	}
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string GetName() const override;
	void Draw(sf::RenderWindow& window) const override;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	int GetWidth() const;
	int GetHeight() const;

private:
	sf::RectangleShape m_rectangle;
	CPoint m_leftTop;
	CPoint m_rightBottom;

};