#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "CPoint.h"
#include "IShape.h"
#include <iostream>

class CTriangle : public IShape
{
public:
	CTriangle(std::string name, int const vertex1_x, int const vertex1_y,
		int const vertex2_x, int const vertex2_y,
		int const vertex3_x, int const vertex3_y)
		: m_vertex1(vertex1_x, vertex1_y),
		m_vertex2(vertex2_x, vertex2_y),
		m_vertex3(vertex3_x, vertex3_y),
		m_name(name)
	{
	}
	std::string GetName() const override;
	int GetArea() const override;
	int GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(sf::RenderWindow& window) const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
	double GetA() const;
	double GetB() const;
	double GetC() const;
private:
	std::string m_name;
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};