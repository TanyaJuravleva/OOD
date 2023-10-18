#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

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
	virtual std::vector<std::unique_ptr<IShapeDecorator>> Ungroup() = 0;
};