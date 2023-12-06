#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "IShapeVisitor.h"
#include "CONSTS.h"

class IShapeDecorator
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string GetName() const = 0;
	virtual void Draw(sf::RenderWindow& window) const = 0;
	virtual std::string ToString() const = 0;

	virtual void SetPosition(int x, int y) const = 0;
	virtual sf::Vector2f GetPosition() const = 0;
	virtual sf::FloatRect GetGlobalBounds() const = 0;
	virtual void DrawFrame(sf::RenderWindow& window) const = 0;
	virtual bool isGroup() const = 0;
	virtual std::vector<IShapeDecorator*> Ungroup() = 0;

	virtual void SetFillColor(IShapeVisitor& visitor) const = 0;
	virtual void SetOutlineThickness(IShapeVisitor& visitor) const = 0;
	virtual void SetOutlineColor(IShapeVisitor& visitor) const = 0;

	std::string GetColorName(sf::Color color) const
	{
		if (color == sf::Color::Blue)
			return NAME_BLUE;
		if (color == sf::Color::Red)
			return NAME_RED;
		if (color == sf::Color::Yellow)
			return NAME_YELLOW;
		if (color == sf::Color::Green)
			return NAME_GREEN;
		if (color == sf::Color::White)
			return NAME_WHITE;
	}

	virtual IShapeDecorator* Clone() = 0;

	virtual ~IShapeDecorator() = default;
};