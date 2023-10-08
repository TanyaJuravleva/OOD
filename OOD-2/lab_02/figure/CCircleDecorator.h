#pragma once
#include "CShapeDecorator.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

const std::string NAME = "CIRCLE";

class CCircleDecorator : public CShapeDecorator
{
public:
	CCircleDecorator(sf::CircleShape circle)
		: m_circle(circle)
	{
	}
protected:
	/*std::string ToString() const override;*/
	double GetShapeArea() const override;
	//double GetPerimeter() const override;
	//std::string GetName() const override;
	//void Draw(sf::RenderWindow& window) const override;
private:
	sf::CircleShape m_circle;
};