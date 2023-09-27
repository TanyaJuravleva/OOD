#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>

class IShape 
{
public:
	virtual int GetArea() const = 0;
	virtual int GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual std::string GetName() const = 0;
	virtual void Draw(sf::RenderWindow& window) const = 0;
	virtual ~IShape() = default;
};