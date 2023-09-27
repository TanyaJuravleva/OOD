#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "CPoint.h"
#include "IShape.h"
#include <iostream>

class CRectangle : public IShape
{
public:
	CRectangle(std::string name, int const leftTop_x, int const leftTop_y,
		int const rightBotton_x, int const rightBotton_y)
		: m_leftTop(leftTop_x, leftTop_y),
		m_rightBottom(rightBotton_x, rightBotton_y),
		m_name(name)
	{
	}
	std::string GetName() const override;
	int GetArea() const override;
	int GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(sf::RenderWindow& window) const override;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	int GetWidth() const;
	int GetHeight() const;
private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
	std::string m_name;
};