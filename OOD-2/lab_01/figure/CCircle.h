#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "CPoint.h"
#include "IShape.h"
#include <iostream>

class CCircle : public IShape
{
public:
	CCircle(std::string name,
		int const center_x,
		int const center_y,
		int const radius)
		:m_center(center_x, center_y),
		m_radius(radius),
		m_name(name)
	{
	}
	int GetArea() const override;
	int GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetName() const override;
	void Draw(sf::RenderWindow& window) const override;
	CPoint GetCenter() const;
	int GetRadius() const;
private:
	std::string m_name;
	CPoint m_center;
	int m_radius;
};