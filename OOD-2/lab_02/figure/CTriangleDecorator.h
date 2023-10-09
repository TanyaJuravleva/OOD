#pragma once
#include "IShapeDecorator.h"
#include "CPoint.h"

const std::string TRIAN_NAME = "RECTANGLE";

class CTriangleDecorator : public IShapeDecorator
{
public:
	CTriangleDecorator(sf::ConvexShape triangle, int vertex1_x, int vertex1_y,
		int vertex2_x, int vertex2_y,
		int vertex3_x, int vertex3_y)
		: m_triangle(triangle),
		m_vertex1(vertex1_x, vertex1_y),
		m_vertex2(vertex2_x, vertex2_y),
		m_vertex3(vertex3_x, vertex3_y)
	{
	}
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string GetName() const override;
	void Draw(sf::RenderWindow& window) const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
	double GetA() const;
	double GetB() const;
	double GetC() const;

private:
	sf::ConvexShape m_triangle;
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};