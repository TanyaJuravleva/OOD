#pragma once
#include "IShapeDecorator.h"

const std::string CIRCLE_NAME = "CIRCLE";

class CCircleDecorator : public IShapeDecorator
{
public:
	CCircleDecorator(sf::CircleShape circle)
		: m_circle(circle)
	{
	}
	std::string ToString() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string GetName() const override;
	void Draw(sf::RenderWindow& window) const override;
private:
	sf::CircleShape m_circle;
};